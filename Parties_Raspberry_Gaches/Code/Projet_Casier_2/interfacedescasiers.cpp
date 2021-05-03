#include "interfacedescasiers.h"
#include "ui_interfacedescasiers.h"


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
    lesGache = new Gache();
    for(int i=0; i<nbCasier; i++){
        lesBoutons[i] = new QPushButton();
        connect(lesBoutons[i], &QPushButton::clicked, this, &InterfaceDesCasiers::onpushButtonMaterielsclicked);
        lesBoutons[i]->setFixedSize(80, 80);
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
    lesGache->ouvrirCasier(numCasier);
    //ui->gridLayout.
}

void InterfaceDesCasiers::miseAJourInterface()
{
    BDD *maBaseDeDonnees;
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
                }
            }
        }
    }
}

int InterfaceDesCasiers::getValue() const
{
    return value;
}

void InterfaceDesCasiers::setValue(int _value)
{
    value = _value;
}

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
    lesGache->ouvrirCasier(numCasier);

}
