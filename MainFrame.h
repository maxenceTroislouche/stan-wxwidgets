#pragma once
#include <wx/wx.h>

// Permet d'utiliser des chaines de caractères avec des accents dans les widgets
#define STR(s) wxString::FromUTF8(s)

typedef struct choiceWindowWidgets
{
    wxStaticText *mainTitle;
    wxButton *fingerprintChoiceButton;
    wxButton *codeChoiceButton;
    wxStaticText *messageText;
} choiceWindowWidgets_t;

typedef struct codeInputWidgets
{
    wxButton *button0;
    wxButton *button1;
    wxButton *button2;
    wxButton *button3;
    wxButton *button4;
    wxButton *button5;
    wxButton *button6;
    wxButton *button7;
    wxButton *button8;
    wxButton *button9;
    wxButton *buttonBackspace;
    wxButton *buttonClear;
} codeInputWidgets_t;

typedef struct codeWindowWidgets
{
    wxStaticText *mainTitle;
    wxStaticText *userIDIndicator;
    wxStaticText *passcodeIndicator;
    wxStaticText *userIDEntered;
    wxStaticText *passcodeEntered;
    wxButton *goBackButton;
    wxButton *connectButton;

    char enteredUserID[5];
    char enteredPasscode[5];

    codeInputWidgets_t userIDButtons;
    codeInputWidgets_t passcodeButtons;
} codeWindowWidgets_t;

typedef struct fingerprintWindowWidgets
{
    wxStaticText *mainTitle;
    wxStaticText *instructionText;
    wxButton *goBackButton;
} fingerprintWindowWidgets_t;

typedef struct connectedWindowWidgets
{
    wxStaticText *mainTitle;
    wxStaticText *usernameIndicator;
    wxButton *disconnectButton;
} connectedWindowWidgets_t;

class MainFrame : public wxFrame
{
private:
    wxPanel *panel;
    choiceWindowWidgets_t choiceWindowWidgets;
    codeWindowWidgets_t codeWindowWidgets;
    fingerprintWindowWidgets_t fingerprintWindowWidgets;
    connectedWindowWidgets_t connectedWindowWidgets;

public:
    MainFrame();
    void handleCodeWindowButtonClicked(wxCommandEvent &evt);
    void handleFingerprintWindowButtonClicked(wxCommandEvent &evt);

    void handleFingerprintWindowGoBackButtonClicked(wxCommandEvent &evt);

    void handleCodeWindowGoBackButtonClicked(wxCommandEvent &evt);
    void handleCodeWindowConnectButtonClicked(wxCommandEvent &evt);

    void handleConnectedWindowDisconnectButtonClicked(wxCommandEvent &evt);

    void displayChoiceWindow(wxString message);
    void destroyChoiceWindow();
    void displayCodeWindow();
    void destroyCodeWindow();
    void displayFingerprintWindow();
    void destroyFingerprintWindow();
    void displayConnectedWindow();
    void destroyConnectedWindow();
};
