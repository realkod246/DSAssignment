//
//  Dialog.h
//  DSAssignment
//
//  Created by Jelani on 15/03/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef Dialog_h
#define Dialog_h



struct record {
    wxString ID;
    wxString fName;
    wxString lName;
    wxString destination;
    wxString season;
    wxString booking;
};


typedef struct record vacationRecord;

class Dialog: public wxDialog {
    
public:
    Dialog(const wxString& title, const wxPoint& pos, const wxSize& size);
    
    wxTextCtrl* idEditBox;
    
    wxTextCtrl* firstNameEditBox;
    wxTextCtrl*  lastNameEditBox;
    wxTextCtrl* destinationEditBox;
    wxTextCtrl* seasonEditBox;
    wxTextCtrl* bookingEditBox;
    wxComboBox* seasonCombo;
    
    
};

Dialog::Dialog ( const wxString& title, const wxPoint& pos,  const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
    //Set up the panel
    wxPanel*    panel = new wxPanel(this, -1);
    
    //Define and position the StaticTexts
    
    wxStaticText *idLabel = new wxStaticText (panel, wxID_ANY, wxT("Student ID"), wxPoint(20, 20) );
    
    wxStaticText *firstNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Name"), wxPoint(15, 55) );
    
    wxStaticText *lastNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Surname"), wxPoint(15, 90) );
    
    
    
    wxStaticText*  destinationLabel = new wxStaticText (panel, wxID_ANY, wxT("Destination"), wxPoint(15, 200) );
    
    wxStaticText *seasonLabel = new wxStaticText(panel, wxID_ANY, wxT("Season"), wxPoint(15, 125) );
    
    wxStaticText *bookingLabel = new wxStaticText(panel, wxID_ANY, wxT("Booking"), wxPoint(15, 160) );
    
    //Define and position the Data Entry Boxes
    
    idEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(116, 16));
    
    bookingEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(85, 160));
    
    firstNameEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(55, 53));
    
    lastNameEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(75, 88));
    
    destinationEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(95,200));
    
    // Edit
    wxArrayString season;
    season.Add(wxT(""));
    season.Add(wxT("Winter"));
    season.Add(wxT("Fall"));
    season.Add(wxT("Sprint"));
    season.Add(wxT("Summer"));
    
    seasonCombo = new wxComboBox( panel, -1, wxT("Winter"), wxPoint(90, 123), wxSize(120, -1), season, wxCB_READONLY);
    
    
    
    
    // Define and position the Response buttons (OK and CANCEL)
    
    // The OK button
    wxButton* ok = new wxButton( panel, wxID_OK, wxT("OK"), wxPoint(100, 240), wxDefaultSize, 0);
    
    // The CANCEL button
    wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("CANCEL"), wxPoint(240, 240), wxDefaultSize, 0 );
    
    // Centre the dialog on the parent's window
    Centre();
    
    Maximize(); // Maximize the window to full definition size
    
}


// Grab the data to display it in the MainEditBox


wxString getRecord(vacationRecord dataRec)
{
    wxString str = wxT("\n\n");
    
    wxString idStr;
    idStr << dataRec.ID;
    
    
    
    str.Append(idStr);
    str.Append(wxT("\t"));
    str.Append(dataRec.fName);
    str.Append(wxT("\t"));
    str.Append(dataRec.lName);
    str.Append(wxT("\t"));
    str.Append(dataRec.destination);
    str.Append(wxT("\t"));
    str.Append(dataRec.season);
    str.Append(wxT("\t"));
    str.Append(dataRec.booking);
    
    str.Append(wxT("\n"));
    
    return str;
}



#endif /* Dialog_h */
