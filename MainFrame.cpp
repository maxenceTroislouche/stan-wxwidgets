#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(1920, 1080))
{
    this->panel = new wxPanel(this);
    this->displayChoiceWindow(STR(""));
}

void MainFrame::handleCodeWindowButtonClicked(wxCommandEvent &evt)
{
    this->destroyChoiceWindow();
    this->displayCodeWindow();
}

void MainFrame::handleFingerprintWindowButtonClicked(wxCommandEvent &evt)
{
    this->destroyChoiceWindow();
    this->displayFingerprintWindow();
}

void MainFrame::handleFingerprintWindowGoBackButtonClicked(wxCommandEvent &evt)
{
    this->destroyFingerprintWindow();
    this->displayChoiceWindow(STR("Fingerprint"));
}

void MainFrame::handleCodeWindowGoBackButtonClicked(wxCommandEvent &evt)
{
    this->destroyCodeWindow();
    this->displayChoiceWindow(STR("Code"));
}

void MainFrame::handleCodeWindowConnectButtonClicked(wxCommandEvent &evt)
{
    // TODO : Lancer la connexion par code !   
}

void MainFrame::handleConnectedWindowDisconnectButtonClicked(wxCommandEvent &evt)
{
    // TODO : Gérer la déconnexion
}

void MainFrame::displayChoiceWindow(wxString message)
{
    this->choiceWindowWidgets.mainTitle = new wxStaticText(this->panel, wxID_ANY, STR("Connexion à Stan"), wxPoint(860, 50), wxSize(200, 50), wxALIGN_CENTER);
    this->choiceWindowWidgets.fingerprintChoiceButton = new wxButton(this->panel, wxID_ANY, STR("Connexion par empreinte digitale"), wxPoint(440, 465), wxSize(400, 150));
    this->choiceWindowWidgets.codeChoiceButton = new wxButton(this->panel, wxID_ANY, STR("Connexion par code"), wxPoint(1100, 465), wxSize(400, 150));


    this->choiceWindowWidgets.messageText = new wxStaticText(this->panel, wxID_ANY, message, wxPoint(860, 350), wxSize(200, 50), wxALIGN_CENTER);

    this->choiceWindowWidgets.codeChoiceButton->Bind(wxEVT_BUTTON, &MainFrame::handleCodeWindowButtonClicked, this);
    this->choiceWindowWidgets.fingerprintChoiceButton->Bind(wxEVT_BUTTON, &MainFrame::handleFingerprintWindowButtonClicked, this);
}

void MainFrame::destroyChoiceWindow()
{
    this->choiceWindowWidgets.mainTitle->Destroy();
    this->choiceWindowWidgets.fingerprintChoiceButton->Destroy();
    this->choiceWindowWidgets.codeChoiceButton->Destroy();
    this->choiceWindowWidgets.messageText->Destroy();

}

void MainFrame::displayCodeWindow()
{
    this->codeWindowWidgets.mainTitle = new wxStaticText(this->panel, wxID_ANY, STR("Connexion à Stan par code"), wxPoint(860, 50), wxSize(200, 50), wxALIGN_CENTER);

    this->codeWindowWidgets.userIDIndicator = new wxStaticText(this->panel, wxID_ANY, STR("Identifiant"), wxPoint(435, 200), wxSize(200, 50), wxALIGN_CENTER);
    this->codeWindowWidgets.userIDEntered = new wxStaticText(this->panel, wxID_ANY, STR("2134"), wxPoint(435, 260), wxSize(200, 50), wxALIGN_CENTER);
    this->codeWindowWidgets.userIDButtons.button1 = new wxButton(this->panel, wxID_ANY, STR("1"), wxPoint(420, 320), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button2 = new wxButton(this->panel, wxID_ANY, STR("2"), wxPoint(500, 320), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button3 = new wxButton(this->panel, wxID_ANY, STR("3"), wxPoint(580, 320), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button4 = new wxButton(this->panel, wxID_ANY, STR("4"), wxPoint(420, 400), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button5 = new wxButton(this->panel, wxID_ANY, STR("5"), wxPoint(500, 400), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button6 = new wxButton(this->panel, wxID_ANY, STR("6"), wxPoint(580, 400), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button7 = new wxButton(this->panel, wxID_ANY, STR("7"), wxPoint(420, 480), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button8 = new wxButton(this->panel, wxID_ANY, STR("8"), wxPoint(500, 480), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button9 = new wxButton(this->panel, wxID_ANY, STR("9"), wxPoint(580, 480), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.buttonClear = new wxButton(this->panel, wxID_ANY, STR("C"), wxPoint(420, 560), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.button0 = new wxButton(this->panel, wxID_ANY, STR("0"), wxPoint(500, 560), wxSize(70, 70));
    this->codeWindowWidgets.userIDButtons.buttonBackspace = new wxButton(this->panel, wxID_ANY, STR("<-"), wxPoint(580, 560), wxSize(70, 70));

    this->codeWindowWidgets.passcodeIndicator = new wxStaticText(this->panel, wxID_ANY, STR("Code"), wxPoint(1350, 200), wxSize(200, 50), wxALIGN_CENTER);
    this->codeWindowWidgets.passcodeEntered = new wxStaticText(this->panel, wxID_ANY, STR("2134"), wxPoint(1350, 260), wxSize(200, 50), wxALIGN_CENTER);
    this->codeWindowWidgets.passcodeButtons.button1 = new wxButton(this->panel, wxID_ANY, STR("1"), wxPoint(1335, 320), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button2 = new wxButton(this->panel, wxID_ANY, STR("2"), wxPoint(1415, 320), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button3 = new wxButton(this->panel, wxID_ANY, STR("3"), wxPoint(1495, 320), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button4 = new wxButton(this->panel, wxID_ANY, STR("4"), wxPoint(1335, 400), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button5 = new wxButton(this->panel, wxID_ANY, STR("5"), wxPoint(1415, 400), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button6 = new wxButton(this->panel, wxID_ANY, STR("6"), wxPoint(1495, 400), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button7 = new wxButton(this->panel, wxID_ANY, STR("7"), wxPoint(1335, 480), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button8 = new wxButton(this->panel, wxID_ANY, STR("8"), wxPoint(1415, 480), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button9 = new wxButton(this->panel, wxID_ANY, STR("9"), wxPoint(1495, 480), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.buttonClear = new wxButton(this->panel, wxID_ANY, STR("C"), wxPoint(1335, 560), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.button0 = new wxButton(this->panel, wxID_ANY, STR("0"), wxPoint(1415, 560), wxSize(70, 70));
    this->codeWindowWidgets.passcodeButtons.buttonBackspace = new wxButton(this->panel, wxID_ANY, STR("<-"), wxPoint(1495, 560), wxSize(70, 70));

    this->codeWindowWidgets.connectButton = new wxButton(this->panel, wxID_ANY, STR("Se connecter"), wxPoint(860, 790), wxSize(200, 50));
    // this->codeWindowWidgets.goBackButton->Bind(wxEVT_BUTTON, &MainFrame::handleCodeWindowGoBackButtonClicked, this);
    this->codeWindowWidgets.goBackButton = new wxButton(this->panel, wxID_ANY, STR("Revenir à la page precedente"), wxPoint(860, 860), wxSize(200, 50));
    this->codeWindowWidgets.goBackButton->Bind(wxEVT_BUTTON, &MainFrame::handleCodeWindowGoBackButtonClicked, this);

}

void MainFrame::destroyCodeWindow()
{
    this->codeWindowWidgets.mainTitle->Destroy();

    this->codeWindowWidgets.userIDIndicator->Destroy();
    this->codeWindowWidgets.userIDEntered->Destroy();
    this->codeWindowWidgets.passcodeIndicator->Destroy();
    this->codeWindowWidgets.passcodeEntered->Destroy();

    this->codeWindowWidgets.userIDButtons.button1->Destroy();
    this->codeWindowWidgets.userIDButtons.button2->Destroy();
    this->codeWindowWidgets.userIDButtons.button3->Destroy();
    this->codeWindowWidgets.userIDButtons.button4->Destroy();
    this->codeWindowWidgets.userIDButtons.button5->Destroy();
    this->codeWindowWidgets.userIDButtons.button6->Destroy();
    this->codeWindowWidgets.userIDButtons.button7->Destroy();
    this->codeWindowWidgets.userIDButtons.button8->Destroy();
    this->codeWindowWidgets.userIDButtons.button9->Destroy();
    this->codeWindowWidgets.userIDButtons.buttonClear->Destroy();
    this->codeWindowWidgets.userIDButtons.button0->Destroy();
    this->codeWindowWidgets.userIDButtons.buttonBackspace->Destroy();

    this->codeWindowWidgets.passcodeButtons.button1->Destroy();
    this->codeWindowWidgets.passcodeButtons.button2->Destroy();
    this->codeWindowWidgets.passcodeButtons.button3->Destroy();
    this->codeWindowWidgets.passcodeButtons.button4->Destroy();
    this->codeWindowWidgets.passcodeButtons.button5->Destroy();
    this->codeWindowWidgets.passcodeButtons.button6->Destroy();
    this->codeWindowWidgets.passcodeButtons.button7->Destroy();
    this->codeWindowWidgets.passcodeButtons.button8->Destroy();
    this->codeWindowWidgets.passcodeButtons.button9->Destroy();
    this->codeWindowWidgets.passcodeButtons.buttonClear->Destroy();
    this->codeWindowWidgets.passcodeButtons.button0->Destroy();
    this->codeWindowWidgets.passcodeButtons.buttonBackspace->Destroy();

    this->codeWindowWidgets.connectButton->Destroy();
    this->codeWindowWidgets.goBackButton->Destroy();
}

void MainFrame::displayFingerprintWindow()
{
    this->fingerprintWindowWidgets.mainTitle = new wxStaticText(this->panel, wxID_ANY, STR("Connexion à Stan par empreinte"), wxPoint(860, 50), wxSize(200, 50), wxALIGN_CENTER);

    // TODO : Lancer l'attente sur le capteur d'empreinte
    this->fingerprintWindowWidgets.instructionText = new wxStaticText(this->panel, wxID_ANY, STR("Placez votre doigt sur le capteur"), wxPoint(860, 500), wxSize(200, 50), wxALIGN_CENTER);
    this->fingerprintWindowWidgets.goBackButton = new wxButton(this->panel, wxID_ANY, STR("Revenir à la page precedente"), wxPoint(860, 600), wxSize(200, 50));
    this->fingerprintWindowWidgets.goBackButton->Bind(wxEVT_BUTTON, &MainFrame::handleFingerprintWindowGoBackButtonClicked, this);
}

void MainFrame::destroyFingerprintWindow()
{
    this->fingerprintWindowWidgets.mainTitle->Destroy();
    this->fingerprintWindowWidgets.instructionText->Destroy();
    this->fingerprintWindowWidgets.goBackButton->Destroy();
}

void MainFrame::displayConnectedWindow()
{
    this->connectedWindowWidgets.mainTitle = new wxStaticText(this->panel, wxID_ANY, STR("Connecté à Stan"), wxPoint(860, 50), wxSize(200, 50), wxALIGN_CENTER);
    this->connectedWindowWidgets.usernameIndicator = new wxStaticText(this->panel, wxID_ANY, STR("MAXENCE"), wxPoint(860, 100), wxSize(200, 50), wxALIGN_CENTER);
    this->connectedWindowWidgets.disconnectButton = new wxButton(this->panel, wxID_ANY, STR("Se déconnecter"), wxPoint(860, 600), wxSize(200, 50));
    this->connectedWindowWidgets.disconnectButton->Bind(wxEVT_BUTTON, &MainFrame::handleConnectedWindowDisconnectButtonClicked, this);
}

void MainFrame::destroyConnectedWindow()
{
    this->connectedWindowWidgets.mainTitle->Destroy();
    this->connectedWindowWidgets.usernameIndicator->Destroy();
    this->connectedWindowWidgets.disconnectButton->Destroy();
}