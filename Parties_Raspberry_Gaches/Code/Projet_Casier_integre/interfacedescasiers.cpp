/**
  @file interfacedescasiers.h
  @brief Implémentation de la classe visuel InterfaceDesCasiers
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe permettant l'affichage des boutons de selection des casiers
  */

#include "interfacedescasiers.h"
#include "ui_interfacedescasiers.h"


/**
 * @brief InterfaceDesCasiers::InterfaceDesCasiers
 * @details lors de la creation permet la récuperation des parametres du casier dans le fichier de configuration
 * @param parent
 * @author Charly Bourgouin
 */
InterfaceDesCasiers::InterfaceDesCasiers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InterfaceDesCasiers)
{
    int positionSystemeX;
    int positionSystemeY;

    QString nomFichierIni="Projet_Casier.ini";
    QFileInfo testFichier(nomFichierIni);
    
    connect(&controlDeGache, &ControleurDeGache::casierFerme, this, &InterfaceDesCasiers::onCasierFerme);
    
    if(testFichier.exists() && testFichier.isFile())
    {
        QSettings paramsSocket(nomFichierIni, QSettings::IniFormat);
        nbCasierX = paramsSocket.value("CASIER/nbcasierx").toInt();
        nbCasierY = paramsSocket.value("CASIER/nbcasiery").toInt();
        nbCasier = paramsSocket.value("CASIER/nbcasier").toInt();
        positionSystemeX = paramsSocket.value("CASIER/positionsystemex").toInt();
        positionSystemeY = paramsSocket.value("CASIER/positionsystemey").toInt();
        tailleDesBoutons = paramsSocket.value("INTERFACE/tailledesboutons").toInt();
    }
    else
    {
        qDebug()<<"fichier ini non valide";
    }
    ui->setupUi(this);
    for(int i=0; i<nbCasier; i++){
        QPushButton *button;
        button = new QPushButton();
        connect(button, &QPushButton::clicked, this, &InterfaceDesCasiers::onpushButtonMaterielsclicked);
        button->setFixedSize(tailleDesBoutons, tailleDesBoutons);
        button->setEnabled(false);
        lesBoutons.push_back(button);
        button=nullptr;
    }
    
    int compteur = 0;
    for(int etage=0; etage<nbCasierY; etage++){
        for(int colonne=0; colonne<nbCasierX; colonne++){
            if(etage != positionSystemeY || colonne != positionSystemeX && compteur<nbCasier){
                ui->gridLayout->addWidget(lesBoutons[compteur], etage, colonne);
                compteur++;
            }
        }
    }
    miseAJourInterface();
}


/**
 * @brief InterfaceDesCasiers::~InterfaceDesCasiers
 * @author Charly Bourgouin
 */
InterfaceDesCasiers::~InterfaceDesCasiers()
{
    delete ui;
}


void InterfaceDesCasiers::onpushButtonMaterielsclicked()
{
    QPushButton *touche = qobject_cast<QPushButton*>(sender());
    for(int i=0; i<nbCasier;i++){
        if(lesBoutons[i] == touche){
            numCasier = i+1;
        }
    }
    pc = Protocol::empreint;
    controlDeGache.ouvrirCasier(numCasier);
}


/**
 * @brief InterfaceDesCasiers::onCasierFerme
 * @details slot activer l'orsque le signale envoyé lors de la fermeture de la porte et reçu
 * @author Charly Bourgouin
 */
void InterfaceDesCasiers::onCasierFerme()
{
    maBaseDeDonnees = new BDD();
    switch (pc) {
    case Protocol::empreint :
        for(int i=0; i<listeMateriel.size(); i++){
            QLayoutItem *item = ui->gridLayout->itemAtPosition(listeMateriel[i].getPositionCasierY(), listeMateriel[i].getPositionCasierX());
            QWidget *wBouton = item->widget();
            QPushButton *bouton = ((QPushButton*) wBouton);
            if(lesBoutons[numCasier-1] == bouton)
            {
                maBaseDeDonnees->MajBDDObjetEmpreinter(listeMateriel[i], numCarte);
            }
        }
        break;
    case Protocol::restitution :

        for(int i=0; i<lesBoutons.size(); i++){
            for(int u=0; u<listeMateriel.size(); u++){
                QLayoutItem *item = ui->gridLayout->itemAtPosition(listeMateriel[u].getPositionCasierY(), listeMateriel[u].getPositionCasierX());
                QWidget *wBouton = item->widget();
                QPushButton *bouton = ((QPushButton*) wBouton);
                if(lesBoutons[i] == bouton)
                {
                    maBaseDeDonnees->MajBDDObjetRendu(listeMateriel[u].getIdMateriel());
                }
            }

        }
        break;
    }
    delete maBaseDeDonnees;
    emit askDisplayFen();
}


/**
 * @brief InterfaceDesCasiers::miseAJourInterface
 * @details synchronisation entre l'interface grace et la base de données
 * @author Charly Bourgouin
 */
void InterfaceDesCasiers::miseAJourInterface()
{
    maBaseDeDonnees = new BDD();
    listeMateriel = maBaseDeDonnees->ListeMaterielEmpreintable();
    
    for(int etage=0; etage<nbCasierY; etage++){
        for(int colonne=0; colonne<nbCasierX; colonne++){
            for(int nummateriel=0; nummateriel<listeMateriel.size(); nummateriel++){
                if(etage == listeMateriel[nummateriel].getPositionCasierY() && colonne == listeMateriel[nummateriel].getPositionCasierX()){
                    QLayoutItem *item = ui->gridLayout->itemAtPosition(etage,colonne);
                    QWidget *wBouton = item->widget();
                    QPushButton *bouton = ((QPushButton*) wBouton);
                    bouton->setIconSize(QSize(tailleDesBoutons-10, tailleDesBoutons-10));
                    bouton->setIcon(QIcon(listeMateriel[nummateriel].getLocalisationImage()));

                    bouton->setEnabled(true);
                }
            }
        }
    }
    delete maBaseDeDonnees;
}


/**
 * @brief InterfaceDesCasiers::ouvrirCasier
 * @details ouvrir un casier a partir de la position sur la grille
 * @param _x position horizontal du casier
 * @param _y position vertical du casier
 * @author Charly Bourgouin
 */
void InterfaceDesCasiers::ouvrirCasier(int _x, int _y)
{
    positionXObjetRendu = _x;
    positionYObjetRendu = _y;
    int numCasier;
    QLayoutItem *item = ui->gridLayout->itemAtPosition(positionYObjetRendu, positionXObjetRendu);
    QWidget *wBouton = item->widget();
    QPushButton *bouton = ((QPushButton*) wBouton);
    for(int i=0; i<nbCasier;i++){
        if(lesBoutons[i] == bouton){
            numCasier = i+1;
        }
    }
    pc = Protocol::restitution;
    controlDeGache.ouvrirCasier(numCasier);
}

/**
 * @brief InterfaceDesCasiers::setNumCarte
 * @details permet de recupérer le numéro de carte
 * @param _numCarte numéro de carte
 * @author Charly Bourgouin
 */
void InterfaceDesCasiers::setNumCarte(const QString &_numCarte)
{
    numCarte = _numCarte;
}
