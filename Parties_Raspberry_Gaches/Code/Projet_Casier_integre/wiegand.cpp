/**
 * @file wiegand.cpp
 * @author Axel DOMINGOS
 * @details Classe Wiegand : Connecte le lecteur
 */

#include "wiegand.h"
#include <wiringPi.h>
#include <time.h>
#include <unistd.h>
#include <memory.h>

static unsigned char __wiegandData[WIEGANDMAXDATA];    // can capture upto 32 bytes of data -- FIXME: Make this dynamically allocated in init?
static unsigned long __wiegandBitCount;                // number of bits currently captured
static struct timespec __wiegandBitTime;               // timestamp of the last bit received (used for timeouts)


/**
 * @brief Wiegand::Wiegand
 * @param d0pin, d1pin, parent
 * @details Constructeur de la classe, initialise les attributs
 */
Wiegand::Wiegand(int d0pin, int d1pin, QObject *parent) : QObject(parent)
{  
    wiringPiSetup() ;
    pinMode(d0pin, INPUT);
    pinMode(d1pin, INPUT);

    wiringPiISR(d0pin, INT_EDGE_FALLING, data0Pulse);
    wiringPiISR(d1pin, INT_EDGE_FALLING, data1Pulse);
}

void Wiegand::data0Pulse()
{
    if (__wiegandBitCount / 8 < WIEGANDMAXDATA)
    {
        __wiegandData[__wiegandBitCount / 8] <<= 1;
        __wiegandBitCount++;
    }
    clock_gettime(CLOCK_MONOTONIC, &__wiegandBitTime);
}

void Wiegand::data1Pulse()
{
    if (__wiegandBitCount / 8 < WIEGANDMAXDATA)
    {
        __wiegandData[__wiegandBitCount / 8] <<= 1;
        __wiegandData[__wiegandBitCount / 8] |= 1;
        __wiegandBitCount++;
    }
    clock_gettime(CLOCK_MONOTONIC, &__wiegandBitTime);
}

void Wiegand::wiegandReset()
{
    memset((void *)__wiegandData, 0, WIEGANDMAXDATA);
    __wiegandBitCount = 0;
}


/**
 * @brief Wiegand::wiegandGetPendingBitCount
 * @details retourne le nombre de bits de données en attente
 */
int Wiegand::wiegandGetPendingBitCount()
{
    struct timespec now, delta;
    clock_gettime(CLOCK_MONOTONIC, &now);
    delta.tv_sec = now.tv_sec - __wiegandBitTime.tv_sec;
    delta.tv_nsec = now.tv_nsec - __wiegandBitTime.tv_nsec;

    if ((delta.tv_sec > 1) || (delta.tv_nsec > WIEGANDTIMEOUT))
        return __wiegandBitCount;

    return 0;
}


/**
 * @brief Wiegand::wiegandReadData
 * wiegandReadData is a simple, non-blocking method to retrieve the last code
 * processed by the API.
 * @details is a pointer to a block of memory where the decoded data will be stored.
 * dataMaxLen : is the maximum number of -bytes- that can be read and stored in data.
 * @return returns the number of -bits- in the current message, 0 if there is no
 * data available to be read, or -1 if there was an error.
 * @note this function clears the read data when called. On subsequent calls,
 * without subsequent data, this will return 0.
 */
int Wiegand::wiegandReadData(void *data, int dataMaxLen)
{
    if (wiegandGetPendingBitCount() > 0) {
        int bitCount = __wiegandBitCount;
        int byteCount = (__wiegandBitCount / 8) + 1;
        memcpy(data, (void *)__wiegandData, ((byteCount > dataMaxLen) ? dataMaxLen : byteCount));

        wiegandReset();
        return bitCount;
    }
    return 0;
}
