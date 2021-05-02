#include "interfacenumcarte.h"
#include "ui_interfacenumcarte.h"

InterfaceNumCarte::InterfaceNumCarte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterfaceNumCarte)
{
    ui->setupUi(this);
}

InterfaceNumCarte::~InterfaceNumCarte()
{
    delete ui;
}

void InterfaceNumCarte::on_pushButton_clicked()
{
    stack = new QStackedWidget(this);

    BDD *maBaseDeDonnee;
    maBaseDeDonnee = new BDD();
    if(maBaseDeDonnee->VerifAdherent(ui->lineEdit->text().toInt())){
        Materiel *materiel = nullptr;
        materiel = maBaseDeDonnee->VerifObjetNonRendu(ui->lineEdit->text().toInt());
        if(materiel==nullptr){
            emit askDisplayFen(1);
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
                Gache lesGaches;

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
