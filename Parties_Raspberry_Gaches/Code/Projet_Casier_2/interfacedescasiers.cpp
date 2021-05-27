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
    int nbCasier;
    QString nomFichierIni="Projet_Casier.ini";
    QFileInfo testFichier(nomFichierIni);

    if(testFichier.exists() && testFichier.isFile())
    {
        QSettings paramsSocket(nomFichierIni, QSettings::IniFormat);
        nbCasierX = paramsSocket.value("CASIER/nbcasierx").toInt();
        nbCasierY = paramsSocket.value("CASIER/nbcasiery").toInt();
        positionSystemeX = paramsSocket.value("CASIER/positionsystemex").toInt();
        positionSystemeY = paramsSocket.value("CASIER/positionsystemey").toInt();
        nbCasier = paramsSocket.value("CASIER/nbcasier").toInt();
    }
    else
    {
        qDebug()<<"fichier ini non valide";
    }
    ui->setupUi(this);
    for(int i=0; i<nbCasier; i++){
        lesBoutons[i] = new QPushButton();
        connect(lesBoutons[i], &QPushButton::clicked, this, &InterfaceDesCasiers::onpushButtonMaterielsclicked);
        lesBoutons[i]->setFixedSize(80, 80);
        lesBoutons[i]->setEnabled(false);
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
    int numCasier;
    QPushButton *touche = qobject_cast<QPushButton*>(sender());
    for(int i=0; i<NBDECASIERS;i++){
        if(lesBoutons[i] == touche){
            numCasier = i+1;
        }
    }
    controlDeGache.ouvrirCasier(numCasier);
    
}


/**
 * @brief InterfaceDesCasiers::miseAJourInterface
 * @details synchronisation entre l'interface grace et la base de données
 * @author Charly Bourgouin
 */
void InterfaceDesCasiers::miseAJourInterface()
{
    maBaseDeDonnees = new BDD();
    std::vector<Materiel> listeMateriel;
    listeMateriel = maBaseDeDonnees->ListeMaterielEmpreintable();

    for(int etage=0; etage<nbCasierY; etage++){
        for(int colonne=0; colonne<nbCasierX; colonne++){
            for(int nummateriel=0; nummateriel<listeMateriel.size(); nummateriel++){
                if(etage == listeMateriel[nummateriel].getPositionCasierY() && colonne == listeMateriel[nummateriel].getPositionCasierX()){
                    QLayoutItem *item = ui->gridLayout->itemAtPosition(etage,colonne);
                    QWidget *wBouton = item->widget();
                    QPushButton *bouton = ((QPushButton*) wBouton);
                    bouton->setText(listeMateriel[nummateriel].getNom());
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
    int numCasier;
    QLayoutItem *item = ui->gridLayout->itemAtPosition(_y, _x);
    QWidget *wBouton = item->widget();
    QPushButton *bouton = ((QPushButton*) wBouton);
    for(int i=0; i<NBDECASIERS;i++){
        if(lesBoutons[i] == bouton){
            numCasier = i+1;
        }
    }
    controlDeGache.ouvrirCasier(numCasier);
    
}
