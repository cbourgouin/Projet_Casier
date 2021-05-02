#include "interfacenumcasier.h"
#include "ui_interfacenumcasier.h"

interfaceNumCasier::interfaceNumCasier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interfaceNumCasier)
{
    ui->setupUi(this);
}

interfaceNumCasier::~interfaceNumCasier()
{
    delete ui;
}

void interfaceNumCasier::on_pushButton_clicked()
{
    BDD *maBaseDeDonnee;
    maBaseDeDonnee = new BDD();
    if(maBaseDeDonnee->VerifAdherent(ui->lineEdit->text().toInt())){
        Materiel *materiel;
        if(materiel==nullptr){
            interfaceNumCasier w;
            w.show();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Vous avez deja empreinter l'objet : " + materiel->getNom());
            msgBox.setInformativeText("Voulez-vous rendre l'objet ? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
        }
    }
    else
    {
        QMessageBox fenetre;
        fenetre.setText("Vous n'etes pas adherent");
    }
}
