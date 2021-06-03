/**
  @file interfacenumcarte.h
  @brief Implémentation de la classe visuel InterfaceNumCarte
  @author Charly Bourgouin
  @date 05/05/2020
  @details Classe permettant l'affichage d'attente d'authentifications et la verification de celui ci.
  */

#include "interfacenumcarte.h"
#include "ui_interfacenumcarte.h"


/**
 * @brief InterfaceNumCarte::InterfaceNumCarte
 * @param parent
 * @author Charly Bourgouin
 */
InterfaceNumCarte::InterfaceNumCarte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterfaceNumCarte)
{
    ui->setupUi(this);
    connect(&LC, &LecteurCarte::nouvelle_carte, this, &InterfaceNumCarte::on_LC_nouvelle_carte);
}


/**
 * @brief InterfaceNumCarte::~InterfaceNumCarte
 * @author Charly Bourgouin
 */
InterfaceNumCarte::~InterfaceNumCarte()
{
    delete ui;
}


/**
 * @brief InterfaceNumCarte::on_pushButton_clicked
 * @details permet la verification de l'adherent et de si il a empreinter un objet
 * @author Charly Bourgouin
 */
void InterfaceNumCarte::on_LC_nouvelle_carte()
{
    QByteArray val= LC.lireTagNFC();
    qDebug() << val.toHex().toUpper();
    numCarte = QString::fromStdString(val.toHex().toUpper().toStdString());
    qDebug() << numCarte;
    BDD *maBaseDeDonnee;
    maBaseDeDonnee = new BDD();
    if(maBaseDeDonnee->VerifAdherent(numCarte)){
        camera.captureImageUtilisateurs();
        Materiel *materiel = nullptr;
        materiel = maBaseDeDonnee->VerifObjetNonRendu(numCarte);
        if(materiel==nullptr){
            emit askDisplayFen(numCarte);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Vous avez deja empreinté l'objet :" + materiel->getNom());
            msgBox.setInformativeText("Voulez-vous le rendre ?");
            msgBox.setStandardButtons( QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Yes){
                ControleurDeGache lesGaches;
                emit ouvrirCasier(materiel->getPositionCasierX(), materiel->getPositionCasierY());
            }
        }
    }
    else
    {
        QMessageBox fenetre;
        fenetre.setText("Vous n'etes pas adherent");
        fenetre.setStandardButtons(QMessageBox::Ok);
        int ret = fenetre.exec();
    }
}
