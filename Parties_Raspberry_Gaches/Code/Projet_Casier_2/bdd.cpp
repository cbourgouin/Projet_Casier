/**
  @file bdd.cpp
  @brief Implémentation de la classe BDD
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe d'accés a la base de donnée
  */

#include "bdd.h"

BDD::BDD()
{
    QString nomFichierIni="Projet_Casier.ini";
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

Materiel *BDD::VerifObjetNonRendu(int _numCarte)
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
    return dernierMaterielEmpreinter;
}

void BDD::MajBDDObjetRendu(int _idObjet)
{
    if(!accesBdd.open())
    {
        qDebug()<<"MajBDDObjetRendu : pb acces bd"<<accesBdd.lastError();
    }
    else
    {
        QSqlQuery requete;

        requete.prepare("update CASIER set CASIER.rendu=1 where CASIER.idmateriel like :im ;");
        requete.bindValue(":im", _idObjet);
        if(!requete.exec()){
            qDebug()<<"MajBDDObjetRendu : pb requete "<<requete.lastError();
        }
    }
}

std::vector<Materiel> BDD::ListeMaterielEmpreintable()
{
    std::vector<Materiel> listeMateriel;
    if(!accesBdd.open())
    {
        qDebug()<<"ListeMaterielEmpreintable : pb acces bd"<<accesBdd.lastError();
    }
    else
    {
        QSqlQuery requete("select MATERIEL.idmateriel, MATERIEL.nom, CASIER.positionx, CASIER.positiony, TYPE.localisationimage"
                            " from MATERIEL, CASIER, TYPE where CASIER.rendu = 1 and MATERIEL.idmateriel like CASIER.idmateriel and MATERIEL.idtype like TYPE.idtype");
        if(!requete.exec()){
            qDebug()<<"ListeMaterielEmpreintable : pb requete "<<requete.lastError();
        }
        while(requete.next()){
            Materiel materiel;
            materiel.setIdMateriel(requete.value("idMateriel").toInt());
            materiel.setNom(requete.value("nom").toString());
            materiel.setPositionCasierX(requete.value("positionx").toInt());
            materiel.setPositionCasierY(requete.value("positiony").toInt());
            materiel.setLocalisationImage(requete.value("localisationimage").toString());
            qDebug()<<requete.value("localisationimage").toString();
            listeMateriel.push_back(materiel);
        }
    }
    return listeMateriel;
}

void BDD::MajBDDObjetEmpreinter(Materiel _objet, int _numCarte)
{

    int idAdherent;

    if(!accesBdd.open())
    {
        qDebug()<<"MajBDDObjetEmpreinter : pb acces bd"<<accesBdd.lastError();
    }
    else
    {
        QSqlQuery requeteMajCasierRendu;
        requeteMajCasierRendu.prepare("update CASIER set CASIER.rendu=0 where CASIER.idmateriel like :im ;");
        requeteMajCasierRendu.bindValue(":im", _objet.getIdMateriel());
        if(!requeteMajCasierRendu.exec()){
            qDebug()<<"MajBDDObjetEmpreinter : pb requete "<<requeteMajCasierRendu.lastError();
        }

        QSqlQuery requeteRecIdAdherent;
        requeteRecIdAdherent.prepare("select idadherent from ADHERENTS where ADHERENTS.numcarte like :nc ;");
        requeteRecIdAdherent.bindValue(":nc", _numCarte);
        if(!requeteRecIdAdherent.exec()){
             qDebug()<<"MajBDDObjetEmpreinter : pb requete "<<requeteRecIdAdherent.lastError();
        }

        idAdherent = requeteRecIdAdherent.value("idadherent").toInt();

        QSqlQuery requeteAjoutLignePreterA;
        requeteAjoutLignePreterA.prepare("insert into PRETERA(idadherent, idmateriel) values( :ia, :im ) ;");
        requeteAjoutLignePreterA.bindValue(":ia", idAdherent);
        requeteAjoutLignePreterA.bindValue(":im", _objet.getIdMateriel());
        if(!requeteAjoutLignePreterA.exec()){
             qDebug()<<"MajBDDObjetEmpreinter : pb requete "<<requeteAjoutLignePreterA.lastError();
        }
    }
}
