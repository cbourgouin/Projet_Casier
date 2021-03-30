#include "bdd.h"


BDD::BDD()
{
    QString nomFichierIni=qApp->applicationName()+".ini";
    QFileInfo testFichier(nomFichierIni);

    if(testFichier.exists() && testFichier.isFile())
    {
        QSettings paramsSocket(nomFichierIni, QSettings::IniFormat);

        accesBdd=QSqlDatabase::addDatabase("QMYSQL");
        accesBdd.setHostName(paramsSocket.value("BDD/ip").toString());
        accesBdd.setDatabaseName(paramsSocket.value("BDD/nomBDD").toString());
        accesBdd.setUserName(paramsSocket.value("BDD/identifiant").toString());
        accesBdd.setPassword(paramsSocket.value("BDD/motDePasse").toString());

    }
    else
    {
        qDebug()<<"fichier ini non valide";
    }
}

bool BDD::VerifAdherent(int _numCarte)
{
    bool reponse = false;
    if(!accesBdd.open())
    {
        qDebug()<<"VerifAdherent : pb acces bd"<<accesBdd.lastError();
    }
    else
    {
        qDebug()<<"VerifAdherent : acces bd ok";
        QSqlQuery requete;
        requete.prepare("select nom from ADHERENTS where numcarte = :nc;");
        requete.bindValue(":nc", _numCarte);
        if(!requete.exec()){
            qDebug()<<"VerifAdherent : pb requete "<<requete.lastError();
        }

        if(requete.size() != 0)
        {
            reponse = true;
        }
        return reponse;
    }

}

Materiel BDD::VerifObjetNonRendu(int _numCarte)
{
    Materiel *dernierMaterielEmpreinter;
    if(!accesBdd.open())
    {
        qDebug()<<"VerifObjetNonRendu : pb acces bd"<<accesBdd.lastError();
    }
    else
    {
        QSqlQuery requeteDernierObjetEmpreinter;
        requeteDernierObjetEmpreinter.prepare("select MATERIEL.idMateriel, MATERIEL.nom, CASIER.positionx, CASIER.positiony"
                        " from MATERIEL, CASIER, ADHERENTS, PRETERA"
                        " where ADHERENTS.numcarte = :nc and ADHERENTS.idadherent like PRETERA.idadherent"
                        " and PRETERA.idmateriel like MATERIEL.idmateriel and MATERIEL.idmateriel"
                        " like CASIER.idmateriel order by PRETERA.datedebut DESC ;");
        requeteDernierObjetEmpreinter.bindValue(":nc", _numCarte);
        if(!requeteDernierObjetEmpreinter.exec()){
            qDebug()<<"VerifObjetNonRendu : pb requete "<<requeteDernierObjetEmpreinter.lastError();
        }

        if(requeteDernierObjetEmpreinter.next()){
            dernierMaterielEmpreinter = new Materiel(requeteDernierObjetEmpreinter.value("idMateriel").toInt(),
                                                     requeteDernierObjetEmpreinter.value("nom").toString(),
                                                     requeteDernierObjetEmpreinter.value("positionx").toInt(),
                                                     requeteDernierObjetEmpreinter.value("positionx").toInt());
        }

        QSqlQuery requeteDernierObjetRendu;
        requeteDernierObjetRendu.prepare("select CASIER.rendu from CASIER where CASIER.idmateriel = :im ;");
        requeteDernierObjetRendu.bindValue(":im", dernierMaterielEmpreinter->getIdMateriel());
        if(!requeteDernierObjetRendu.exec()){
            qDebug()<<"VerifObjetNonRendu : pb requete "<<requeteDernierObjetEmpreinter.lastError();
        }
        if(requeteDernierObjetRendu.next()){
            int rendu = requeteDernierObjetRendu.value("rendu").toInt();
            if(rendu == 1){
                dernierMaterielEmpreinter = nullptr;
            }
            qDebug()<<requeteDernierObjetRendu.value("rendu").toInt();
        }
    }
    return *dernierMaterielEmpreinter;
}
