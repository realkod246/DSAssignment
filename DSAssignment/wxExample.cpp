/************************************************************************************
 *  Step 1: Always include the header file wx.h					    
 *************************************************************************************/
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/listbox.h>
#include <wx/numdlg.h>
#include <wx/textdlg.h>



#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>


#include "Queue.h"
#include "deque.h"
#include "pQueue.h"
#include "Dialog.h"
#include "stack.h"

using namespace std;

Queue *theQueue = new Queue();
Deque *theDeque = new Deque();
PQueue *thePQ = new PQueue();
stack *theStack = new stack();


string to_String(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}


string to_String(float theFloat) {
    stringstream ss;
    ss << fixed << setprecision(2) << theFloat;
    return ss.str();
}


int to_int(string theString) {
    int value;
    stringstream ss(theString);
    ss >> value;
    return value;
}

string makeTheRecord(int ID, string fName, string lName, string destination, string season, string booking) {
    string str = to_String(ID);
    
    while (fName.size() < 20) {
        fName.append(" ");
    }
    
    while (lName.size() < 20) {
        lName.append(" ");
    }
    
    while (destination.size() < 20) {
        destination.append(" ");
    }
    
    while (season.size() < 20) {
        season.append(" ");
    }
    
    while (booking.size() < 20) {
        booking.append(" ");
    }
    
    str.append(" ");
    str.append(fName);
    str.append(lName);
    str.append(destination);
    str.append(season);
    str.append(booking);
    return str;
}


/************************************************************************************
 *  Step 2: Name an inherited application class from wxApp and declare it with 
 *	  the function to execute the program				    
 *************************************************************************************/
class MyApp: public wxApp
    {
        virtual bool OnInit();
    };



/************************************************************************************
 *   Step 3: Declare the inherited main frame class from wxFrame. In this class 
 *	   also will ALL the events handlers be declared    
 *************************************************************************************/
class MyFrame: public wxFrame
{
    private:
        DECLARE_EVENT_TABLE() //To declare events items
    
    public:
        MyFrame(const wxString& title, const wxPoint& pos, 
                const wxSize& size);
        
    
    void OnAbout(wxCommandEvent& event); 	//handle for About function
    
    
    // File Functions
    void onOpenFile(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);     //handle for Quit function
    void OnDisplayFile(wxCommandEvent& event); // handle Displaying file
    
    
    // Queue Functions
    void onCreateQueue(wxCommandEvent& event);
    void onAddDataToQueue(wxCommandEvent& event);
    void onDisplayAllOfQueue(wxCommandEvent& event);
    void onShowHeadOfQueue(wxCommandEvent& event);
    void onShowTailOfQueue(wxCommandEvent& event);
    void onQueueDequeue(wxCommandEvent& event);
    
    // Deque Functions
    void onCreateDeque(wxCommandEvent& event);
    void onAddHeadDeque(wxCommandEvent& event);
    void onAddTailDeque(wxCommandEvent& event);
    void onDisplayAllOfDeque(wxCommandEvent& event);
    void onShowHeadOfDeque(wxCommandEvent& event);
    void onShowTailOfDeque(wxCommandEvent& event);
    void onDequeueHeadOfDeque(wxCommandEvent& event);
    void onDequeueTailOfDeque(wxCommandEvent& event);
    
    // Priority Queue Functions
    void onCreatePQ(wxCommandEvent& event);
    void OnPQAddData(wxCommandEvent& event);
    void OnPQDisplayAll(wxCommandEvent& event);
    void OnPQShowHead(wxCommandEvent& event);
    void OnPQShowTail(wxCommandEvent& event);
    void OnPQDequeue(wxCommandEvent& event);
    
    //Stack Functions
    void OnCreateStack(wxCommandEvent& event);
    void OnPop(wxCommandEvent& event);
    void OnPush(wxCommandEvent& event);
    void OnStackDisplayAll(wxCommandEvent& event);
    
    
    void OnHelp(wxCommandEvent& event);     //handle for Help function
    
    wxString currentDocPath;
    wxTextCtrl* mainEditBox;
    wxTextCtrl* filenameTextBox;
    
    };



/************************************************************************************
 *  Step 4. Declare the compiler directives				    
 *************************************************************************************/
DECLARE_APP(MyApp)		// Declare Application class
IMPLEMENT_APP(MyApp)		// Create Application class object

// Enum Containing all the ID's
enum
        {
            ID_Quit = wxID_HIGHEST + 1,
            ID_OpenFile,
            ID_Save,
            ID_SaveAs,
            ID_DisplayFile,
            
            
            
            
            ID_About,
            ID_Help,
            
            
            
            ID_Queue,
            ID_Deque,
            ID_PQueue,
            ID_Stack,
            ID_BST,
            ID_AVLTree,
            ID_Heap,
            ID_RBTree,
            ID_Splay,
            ID_Set,
            ID_CreateQueue,
            ID_AddData,
            ID_DisplayAllOfQueue,
            ID_ShowHead,
            ID_ShowTail,
            ID_Dequeue,
            ID_CreateDeque,
            ID_AddHead,
            ID_AddTail,
            ID_DequeDisplayAll,
            ID_DequeShowHead,
            ID_DequeShowTail,
            ID_DequeueHead,
            ID_DequeueTail,
            ID_CreatePQ,
            ID_PQAddData,
            ID_PQDisplayAll,
            ID_PQShowTail,
            ID_PQShowHead,
            ID_PQDequeue,
            ID_CreateStack,
            ID_Push,
            ID_Pop,
            ID_StackDisplayAll,
            ID_CreateBST,
            ID_BSTAddData,
            ID_DeleteData,
            ID_BSTInOrder,
            ID_BSTPreOrder,
            ID_BSTPostOrder,
            ID_CreateAVL,
            ID_AVLAddData,
            ID_AVLDeleteData,
            ID_AVLInOrder,
            ID_AVLPreOrder,
            ID_AVLPostOrder,
            ID_CreateHeap,
            ID_HeapAddData,
            ID_HeapDeleteData,
            ID_HeapDisplayAll,
            ID_SortHeap,
            ID_CreateRBT,
            ID_RBTAddData,
            ID_RBTDeleteData,
            ID_RBTInOrder,
            ID_RBTPreOrder,
            ID_RBTPostOrder,
            ID_CreateSplay,
            ID_SplayAddData,
            ID_SplayDeleteData,
            ID_SplayInOrder,
            ID_SplayPreOrder,
            ID_SplayPostOrder,
            ID_CreateSets,
            ID_SetsAddData,
            ID_DisplaySetA,
            ID_DisplaySetB,
            ID_DisplayInterception,
            ID_DisplayUnion,
            ID_DeleteFromSetA,
            ID_DeleteFromSetB,
            
            
            
            
            
        };

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
// Events for File Menu
        EVT_MENU ( ID_Quit, MyFrame::OnQuit )
        EVT_MENU(ID_OpenFile, MyFrame::onOpenFile)
        EVT_MENU(ID_Save, MyFrame::OnSave)
        EVT_MENU(ID_SaveAs, MyFrame::OnSaveAs)
        EVT_MENU(ID_DisplayFile, MyFrame::OnDisplayFile)

// Events for Queue
EVT_MENU(ID_CreateQueue, MyFrame::onCreateQueue)
EVT_MENU(ID_AddData, MyFrame::onAddDataToQueue)
EVT_MENU(ID_DisplayAllOfQueue, MyFrame::onDisplayAllOfQueue)
EVT_MENU(ID_ShowHead, MyFrame::onShowHeadOfQueue)
EVT_MENU(ID_ShowTail, MyFrame::onShowTailOfQueue)
EVT_MENU(ID_Dequeue, MyFrame::onQueueDequeue)

// Events for Deque
EVT_MENU(ID_CreateDeque, MyFrame::onCreateDeque)
EVT_MENU(ID_AddHead, MyFrame::onAddHeadDeque)
EVT_MENU(ID_AddTail, MyFrame::onAddTailDeque)
EVT_MENU(ID_DequeDisplayAll, MyFrame::onDisplayAllOfDeque)
EVT_MENU(ID_DequeShowHead, MyFrame::onShowHeadOfDeque)
EVT_MENU(ID_DequeShowTail, MyFrame::onShowTailOfDeque)
EVT_MENU(ID_DequeueHead, MyFrame::onDequeueHeadOfDeque)
EVT_MENU(ID_DequeueTail, MyFrame::onDequeueTailOfDeque)


// Events for Priority Queue
EVT_MENU(ID_CreatePQ, MyFrame::onCreatePQ)
EVT_MENU(ID_PQAddData, MyFrame::OnPQAddData)
EVT_MENU(ID_PQDisplayAll, MyFrame::OnPQDisplayAll)
EVT_MENU(ID_PQShowHead, MyFrame::OnPQShowHead)
EVT_MENU(ID_PQShowTail, MyFrame::OnPQShowTail)
EVT_MENU(ID_PQDequeue, MyFrame::OnPQDequeue)

//Events for Stack
EVT_MENU (ID_CreateStack, MyFrame::OnCreateStack)
EVT_MENU (ID_Pop, MyFrame::OnPop)
EVT_MENU (ID_Push, MyFrame::OnPush)
EVT_MENU (ID_StackDisplayAll, MyFrame::OnStackDisplayAll )


EVT_MENU ( ID_About, MyFrame::OnAbout )
EVT_MENU ( ID_Help, MyFrame::OnHelp )

        //EVT_MENU ( ID_Queue, MyFrame::onQueue )
        //EVT_MENU ( ID_Deque, MyFrame::onDeque )
        //EVT_MENU ( ID_PQueue, MyFrame::onPQueue )
        //EVT_MENU ( ID_Stack, MyFrame::onStack )
        //EVT_MENU ( ID_BST, MyFrame::onBST )
        //EVT_MENU ( ID_AVLTree, MyFrame::onAVLTree )
        //EVT_MENU ( ID_Heap, MyFrame::onHeap )
        //EVT_MENU ( ID_RBTree, MyFrame::onRBTree )
        //EVT_MENU ( ID_Splay, MyFrame::onSplay )
END_EVENT_TABLE () 





/************************************************************************************
 *  Step 5.  Define the Application class function to initialize the application
 *************************************************************************************/
bool MyApp::OnInit()
    {
        // Create the main application window
        MyFrame *frame = new MyFrame( wxT("COMP2611 -Pelican Travels Database"), wxPoint(50,50),
                                      wxSize(500,400) );
    
        // Display the window
        frame->Show(TRUE);
    
        SetTopWindow(frame);
    
        return TRUE;
    
    }


/************************************************************************************
 *  Step 6:   Define the Constructor functions for the Frame class
 *************************************************************************************/
MyFrame::MyFrame ( const wxString& title, const wxPoint& pos, const wxSize& size) : 
                    wxFrame((wxFrame *)NULL, -1, title, pos, size)
    {
        // Set the frame icon - optional
        SetIcon(wxIcon(wxT("uwiIcon.xpm")));
    
        // Create a "File" main-menu item
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(ID_OpenFile, wxT("Open File..."), wxT("Open an Existing File" ));
        menuFile->AppendSeparator();
        menuFile->Append( ID_DisplayFile, wxT("Display File..."), wxT("&Display Contents of the Opened File") );
        menuFile->AppendSeparator();
        menuFile->Append( ID_Save,        wxT("Save File"      ), wxT("&Save Opened File") );
        menuFile->AppendSeparator();
        menuFile->Append( ID_SaveAs,      wxT("Save As..."     ), wxT("&Save Display as a New File") );
        menuFile->AppendSeparator();
        menuFile->Append( ID_About, wxT("&About the Creator") );
        menuFile->AppendSeparator();
        
        menuFile->Append( ID_Quit, wxT("&Exit the Program") );
        
    
        //Append menu items (About and Exit) to the "File" menu item
       
        
        // Create a Display File main-menu item
        wxMenu *menuDisplayFile = new wxMenu;
        
        
        
        // Create a Queue main-menu item
        wxMenu *menuQueue = new wxMenu;
        menuQueue -> Append(ID_CreateQueue, wxT("&Create a Queue"));
        menuQueue -> Append(ID_AddData, wxT("&Add Data to Queue"));
        menuQueue -> Append(ID_DisplayAllOfQueue, wxT("Display All of Queue"));
        menuQueue -> Append(ID_ShowHead, wxT("Show Head of Queue"));
        menuQueue -> Append(ID_ShowTail, wxT("Show Tail of Queue"));
        menuQueue -> Append(ID_Dequeue, wxT("Dequeue from Queue"));
        
        // Create a Deque main-menu item
        wxMenu *menuDeque = new wxMenu;
        menuDeque -> Append(ID_CreateDeque, wxT("&Create Deque"));
        menuDeque -> Append(ID_AddHead, wxT("&Add to Head of Deque"));
        menuDeque -> Append(ID_DequeDisplayAll, wxT("Display All of the Deque"));
        menuDeque -> Append(ID_DequeShowHead, wxT("Show Head of Deque"));
        menuDeque -> Append(ID_DequeShowTail, wxT("Show Tail of Deque"));
        menuDeque -> Append(ID_DequeueHead, wxT("Dequeue Head of Deque"));
        menuDeque -> Append(ID_DequeueTail, wxT("&Dequeue Tail of Deque"));
        
        
        // Create a Priority Queue main-menu item
        wxMenu *menuPQueue = new wxMenu;
        menuPQueue -> Append(ID_CreatePQ, wxT("&Create a Priority Queue"));
        menuPQueue -> Append(ID_PQAddData, wxT("&Add Data to Priority Queue"));
        menuPQueue -> Append(ID_PQDisplayAll, wxT("Display All of Priority Queue"));
        menuPQueue -> Append(ID_PQShowHead, wxT("Show Head of Priority Queue"));
        menuPQueue -> Append(ID_PQShowTail, wxT("Show Tail of Priority Queue"));
        menuPQueue -> Append(ID_PQDequeue, wxT("Dequeue from Priority Queue"));
        
        
        
        // Create a Stack main-menu item
        wxMenu *menuStack = new wxMenu;
        menuStack -> Append(ID_CreateStack, wxT("Create a Stack"));
        menuStack -> Append(ID_Push, wxT("Push to Stack"));
        menuStack -> Append(ID_Pop, wxT("Pop from Stack"));
        menuStack -> Append(ID_StackDisplayAll, wxT("Display All of Stack"));
        
        // Create a BST main-menu item
        wxMenu *menuBST = new wxMenu;
        menuBST -> Append(ID_CreateBST, wxT("Create BST"));
        menuBST -> Append(ID_AddData, wxT("Add Data"));
        menuBST -> Append(ID_DeleteData, wxT("Delete Data"));
        menuBST -> Append(ID_BSTInOrder, wxT("Inorder"));
        menuBST -> Append(ID_BSTPreOrder, wxT("Preorder"));
        menuBST -> Append(ID_BSTPostOrder, wxT("Postorder"));
        
        
        
        // Create a AVL main-menu item
        wxMenu *menuAVL = new wxMenu;
        menuAVL -> Append(ID_CreateAVL, wxT("Create AVL"));
        menuAVL -> Append(ID_AVLAddData, wxT("Add Data"));
        menuAVL -> Append(ID_AVLDeleteData, wxT("Delete Data"));
        menuAVL -> Append(ID_AVLInOrder, wxT("Inorder"));
        menuAVL -> Append(ID_AVLPreOrder, wxT("Preorder"));
        menuAVL -> Append(ID_AVLPostOrder, wxT("Postorder"));
        
        // Create a Heap main-menu item
        wxMenu *menuHeap = new wxMenu;
        menuHeap -> Append(ID_CreateHeap, wxT("Create Heap"));
        menuHeap -> Append(ID_HeapAddData, wxT("Add Data"));
        menuHeap -> Append(ID_HeapDeleteData, wxT("Delete Data"));
        menuHeap -> Append(ID_HeapDisplayAll, wxT("Display All"));
        menuHeap -> Append(ID_SortHeap, wxT("Heap Sort"));
        
        
        
        // Create a RB Tree main-menu item
        wxMenu *menuRBTree = new wxMenu;
        menuRBTree -> Append(ID_CreateRBT, wxT("Create RBT"));
        menuRBTree -> Append(ID_RBTAddData, wxT("Add Data"));
        menuRBTree -> Append(ID_RBTDeleteData, wxT("Delete Data"));
        menuRBTree -> Append(ID_RBTInOrder, wxT("Inorder"));
        menuRBTree -> Append(ID_RBTPreOrder, wxT("Preorder"));
        menuRBTree -> Append(ID_RBTPostOrder, wxT("Postorder"));
        
        // Create a Splay main-menu item
        wxMenu *menuSplay = new wxMenu;
        menuSplay -> Append(ID_CreateSplay, wxT("Create Splay"));
        menuSplay -> Append(ID_SplayAddData, wxT("Add Data"));
        menuSplay -> Append(ID_SplayDeleteData, wxT("Delete Data"));
        menuSplay -> Append(ID_SplayInOrder, wxT("Inorder"));
        menuSplay -> Append(ID_SplayPreOrder, wxT("Preorder"));
        menuSplay -> Append(ID_SplayPostOrder, wxT("Postorder"));
        
        
        // Create a Set main-menu item
        wxMenu *menuSet = new wxMenu;
        menuSet -> Append(ID_CreateSets, wxT("Create Sets"));
        menuSet -> Append(ID_SetsAddData, wxT("Add Data"));
        menuSet -> Append(ID_DisplaySetA, wxT("Display SetA"));
        menuSet -> Append(ID_DisplaySetB, wxT("Display SetB"));
        menuSet -> Append(ID_DisplayInterception, wxT("Display Interception"));
        menuSet -> Append(ID_DisplayUnion, wxT("Display Union"));
        menuSet -> Append(ID_DeleteFromSetA, wxT("Delete from SetA"));
        menuSet -> Append(ID_DeleteFromSetB, wxT("Delete from SetB"));
        
    
        //Create a "Help" main-menu item
        wxMenu *menuHelp = new wxMenu;
    
        //Append "Help" sub-menu item to it 
        menuHelp->Append(ID_Help, wxT("&Help..."));
    
        //Append "About" sub-menu item to it 
        menuHelp->Append(ID_About, wxT("&About"));
    
        //Create a Main menu bar
        wxMenuBar *menuBar = new wxMenuBar;
    
        //Append the main menu items ("File" and "Help") to it
        menuBar->Append( menuFile, wxT("&File") );
        menuBar -> Append(menuDisplayFile, wxT("&Display File") );
        menuBar -> Append(menuQueue, wxT("&Queue") );
        menuBar -> Append(menuDeque, wxT("&Deque") );
        menuBar -> Append(menuPQueue, wxT("&Priority Queue") );
        menuBar -> Append(menuStack, wxT("&Stack") );
        menuBar -> Append(menuBST, wxT("&BST") );
        menuBar -> Append(menuAVL, wxT("&AVLTree") );
        menuBar -> Append(menuHeap, wxT("&Heap") );
        menuBar -> Append(menuRBTree, wxT("&RB Tree") );
        menuBar -> Append(menuSplay, wxT("&Splay") );
        menuBar -> Append(menuSet, wxT("&Set") );
        
        
        menuBar->Append( menuHelp, wxT("&Help") );
        
    
        // ... and now... attach this main menu bar to the frame
        SetMenuBar( menuBar );
    
        // Create a status bar just for fun
        CreateStatusBar(3);
    
    
        //Put something in the first section of the status bar
        SetStatusText( wxT("Ready...") );
    
        //Put something in the first section of the status bar
        SetStatusText( wxT("Jelani Nicholls"), 1 );
        
        //Put something in the second section of the status bar
        SetStatusText( wxT("414001005"), 2 );
        wxPanel     *panel     = new wxPanel(this, -1);
        wxBoxSizer     *vbox     = new wxBoxSizer(wxVERTICAL);        //Vertical sizer for main window
        wxBoxSizer     *hbox1     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for main window
        
        //Add two textboxes to the panel for data display
        wxBoxSizer     *hbox2     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for filename window
        wxBoxSizer     *hbox3     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for display window
        
        wxStaticText     *fileLabel     = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
        wxStaticText     *displayLabel     = new wxStaticText(panel, wxID_ANY, wxT("Display"));
        
        //Initialize the filename textbox window
        filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
        
        //Initialize the display window
        mainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
                                     wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH | wxTE_BESTWRAP);
        
        //Position the labels and textboxes in the panel
        hbox1->Add(fileLabel, 0, wxRIGHT, 8);
        hbox1->Add(filenameTextBox, 1);
        vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
        
        vbox->Add(-1, 10);
        hbox2->Add(displayLabel, 0);
        vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
        vbox->Add(-1, 10);
        
        hbox3->Add(mainEditBox, 1, wxEXPAND);
        vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
        
        vbox->Add(-1, 25);
        panel->SetSizer(vbox);
        
        Centre();
        
    
    }


/************************************************************************************
 *  Step 7:  Define member functions for the Frame class
 *************************************************************************************/
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
    {
        Close ( TRUE );
    }


void MyFrame::onOpenFile(wxCommandEvent& event) {
    wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString, (wxT("Data Files (*.dat)|*.dat)|Text files (*.txt)|*.txt|All files(*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);
    
    if (OpenDialog -> ShowModal() == wxID_OK) {
        currentDocPath = OpenDialog->GetPath();
        
        filenameTextBox->Clear();
        filenameTextBox->AppendText(currentDocPath);
        
        mainEditBox->LoadFile(currentDocPath);
        
        
    }
}


void MyFrame::OnAbout ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxString msg;
    
        msg.Printf(wxT("Creator: Jelani Nicholls 414001005. Version: %s"), wxVERSION_STRING);
    
        wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
    }


void MyFrame::OnSave( wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->SaveFile(currentDocPath);
}

void MyFrame::OnSaveAs( wxCommandEvent& WXUNUSED ( event )) {
    wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                                                wxEmptyString, wxEmptyString,
                                                (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                                                wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    
    // Creates a Save Dialog with 4 file types
    if (SaveDialog->ShowModal() == wxID_OK)     // If the user clicked "OK"
    {
        currentDocPath = SaveDialog->GetPath();
        
        // set the path of our current document to the file the user chose to save under
        mainEditBox->SaveFile(currentDocPath); // Save the file to the selected path
        
        // Set the Title to reflect the file open
        SetTitle(wxString(wxT("COMP2611 - PElecan")));
    }
}

void MyFrame::OnDisplayFile(wxCommandEvent& WXUNUSED ( event )) {
    // Creates a "open file" dialog with 4 file types
    wxFileDialog *OpenDialog = new wxFileDialog( this, (wxT("Choose a file to open")),
                                                wxEmptyString, wxEmptyString,
                                                (wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
                                                wxFD_OPEN, wxDefaultPosition);
    
    mainEditBox->Clear();
    
    mainEditBox->LoadFile(currentDocPath);
}


//===================================================================================\\
//=========== Definitions for the Queue Functions ===================================\\
//===================================================================================\\

void MyFrame::onCreateQueue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    string record;
    string theRecord;
    string fileLine;
    
    int theID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
    theQueue ->~Queue();
    
    ifstream inFile;
    inFile.open(currentDocPath.mb_str(), ios::in);
    
    if (!inFile) {
        mainEditBox->AppendText(wxT("\n\n\nAin't no data in here..\n\n"));
        return;
    }
    //getline(inFile, fileLine);
    while (!inFile.eof()) {
        getline(inFile, fileLine, '\n');
        
        istringstream ss(fileLine);
        getline(ss, record, ' ');
        inFile >> theID;
        inFile.ignore(',', '\t');
        inFile >> fName >> lName;
        inFile >> destination >> season >> booking;
        cout << season<< endl;
        theQueue->enqueue(theID, fName, lName, destination, season, booking);
        record = makeTheRecord(theID, fName, lName, destination, season, booking);
        record.append("\n");
        
        wxString wxRecord(record.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxRecord);
        
        
        record = "";
    }
    inFile.close();
    }


void MyFrame::onAddDataToQueue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    
    vacationRecord data;
    Dialog *datadialog = new Dialog( wxT("Data Entry for Queue"),
                                            wxPoint(200,200), wxSize(420,420) );
    if (datadialog->ShowModal() == wxID_OK) {
        data.ID = datadialog-> idEditBox->GetValue();
        data.fName = datadialog -> firstNameEditBox->GetValue();
        data.lName = datadialog -> lastNameEditBox->GetValue();
        data.destination = datadialog -> destinationEditBox->GetValue();
        data.booking = datadialog -> bookingEditBox->GetValue();
        data.season = datadialog -> seasonCombo->GetValue();
        
        mainEditBox->Clear();
        
        int ID =to_int(string(data.ID.mb_str()));
        string fName = string(data.fName.mb_str());
        string lName = string(data.lName.mb_str());
        string destination = string(data.destination.mb_str());
        string booking = string(data.booking.mb_str());
        string season = string(data.season.mb_str());
        
        mainEditBox->AppendText(getRecord(data));
        theQueue -> enqueue(ID, fName, lName, destination, season, booking);
    }
    
    else {
        datadialog -> Close();

    }
    datadialog -> Destroy();
    
    
}

void MyFrame::onDisplayAllOfQueue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    
    string all = theQueue->displayQueue();;
    string record = all;
    if (all.size() == 0)
        mainEditBox->AppendText(wxT("\n\n\t\tThe Queue is empty!\n"));
    else
    {
        
        
        
        
        wxString wxRecords(all.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Records of the Queue*****\n\n"));
        mainEditBox->AppendText(wxRecords);
        
    }
}

void MyFrame::onShowHeadOfQueue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    string head = theQueue->front();
    
    string record = head;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Head of the Queue*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::onShowTailOfQueue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    string tail = theQueue->back();
    
    string record = tail;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Tail of the Queue*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::onQueueDequeue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    string del = theQueue->dequeue();
    string record = del;
    
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Removed Record*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}


//===================================================================================\\
//=========== Definitions for the Deque Functions ===================================\\
//===================================================================================\\

void MyFrame::onCreateDeque(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox -> Clear();
    
    string record;
    string theRecord;
    string fileLine;
    
    int theID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
    theDeque -> ~Deque();
    
    ifstream inFile;
    inFile.open(currentDocPath.mb_str(), ios::in);
    
    if (!inFile) {
        mainEditBox->AppendText(wxT("\n\n\nAin't no data in here..\n\n"));
        return;
    }
    
    while (!inFile.eof()) {
        getline(inFile, fileLine, '\n');
        
        istringstream ss(fileLine);
        getline(ss, record, ' ');
        inFile >> theID;
        inFile.ignore(',', '\t');
        inFile >> fName;
        inFile >> lName;
        inFile >> destination >> season;
        inFile >> booking;
        cout << booking << endl;
        if (booking == "Gifted") {
            theDeque->push_front(theID, fName, lName, destination, season, booking);
            record = makeTheRecord(theID, fName, lName, destination, season, booking);
            record.append("\n");
        }
        else {
        theDeque->push_back(theID, fName, lName, destination, season, booking);
        record = makeTheRecord(theID, fName, lName, destination, season, booking);
        record.append("\n");
        }
        
        
        
        
        
        
        wxString wxRecord(record.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxRecord);
        
        record = "";
        
        
        
        
    }
    inFile.close();
}

void MyFrame::onAddHeadDeque(wxCommandEvent& WXUNUSED (event)) {
    mainEditBox -> Clear();
    record data;
    
    Dialog *datadialog = new Dialog( wxT("Data Entry for Queue"),
                                    wxPoint(200,200), wxSize(420,420) );
    if (datadialog->ShowModal() == wxID_OK) {
        data.ID = datadialog-> idEditBox->GetValue();
        data.fName = datadialog -> firstNameEditBox->GetValue();
        data.lName = datadialog -> lastNameEditBox->GetValue();
        data.destination = datadialog -> destinationEditBox->GetValue();
        data.booking = datadialog -> bookingEditBox->GetValue();
        data.season = datadialog -> seasonCombo->GetValue();
        
        mainEditBox->Clear();
        
        int ID =to_int(string(data.ID.mb_str()));
        string fName = string(data.fName.mb_str());
        string lName = string(data.lName.mb_str());
        string destination = string(data.destination.mb_str());
        string booking = string(data.booking.mb_str());
        string season = string(data.season.mb_str());
        
        mainEditBox->AppendText(getRecord(data));
        theDeque -> push_front(ID, fName, lName, destination, season, booking);
    }
    
    else {
        datadialog -> Close();
        
    }
    datadialog -> Destroy();
}

void MyFrame::onAddTailDeque(wxCommandEvent& WXUNUSED (event)) {
    mainEditBox -> Clear();
    record data;
    
    Dialog *datadialog = new Dialog( wxT("Data Entry for Deque"),
                                    wxPoint(200,200), wxSize(420,420) );
    if (datadialog->ShowModal() == wxID_OK) {
        data.ID = datadialog-> idEditBox->GetValue();
        data.fName = datadialog -> firstNameEditBox->GetValue();
        data.lName = datadialog -> lastNameEditBox->GetValue();
        data.destination = datadialog -> destinationEditBox->GetValue();
        data.booking = datadialog -> bookingEditBox->GetValue();
        data.season = datadialog -> seasonCombo->GetValue();
        
        mainEditBox->Clear();
        
        int ID =to_int(string(data.ID.mb_str()));
        string fName = string(data.fName.mb_str());
        string lName = string(data.lName.mb_str());
        string destination = string(data.destination.mb_str());
        string booking = string(data.booking.mb_str());
        string season = string(data.season.mb_str());
        
        mainEditBox->AppendText(getRecord(data));
        theDeque -> push_back(ID, fName, lName, destination, season, booking);
    }
    
    else {
        datadialog -> Close();
        
    }
    datadialog -> Destroy();
}

void MyFrame::onDisplayAllOfDeque(wxCommandEvent& WXUNUSED (event )) {
    mainEditBox->Clear();
    
    
    string all = theDeque->display();
    string record = all;
    if (all.size() == 0)
        mainEditBox->AppendText(wxT("\n\n\t\tThe Queue is empty!\n"));
    else
    {
        
        
        
        
        wxString wxRecords(all.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Records of the Queue*****\n\n"));
        mainEditBox->AppendText(wxRecords);
    }
    
}

void MyFrame::onShowHeadOfDeque(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    string head = theDeque->begin();
    
    string record = head;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Head of the Deque*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::onShowTailOfDeque(wxCommandEvent& WXUNUSED ( event ) ) {
    mainEditBox->Clear();
    string head = theDeque->end();
    
    string record = head;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Head of the Deque*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::onDequeueHeadOfDeque(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    string del = theDeque->pop_front();
    string record = del;
    
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Removed Record*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::onDequeueTailOfDeque(wxCommandEvent& WXUNUSED (event)) {
    mainEditBox->Clear();
    
    string del = theDeque->pop_back();
    string record = del;
    
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Removed Record*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

//===================================================================================\\
//=========== Definitions for the Priority Queue Functions ===========================\\
//===================================================================================\\

void MyFrame::onCreatePQ(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox -> Clear();
    
    string record;
    string theRecord;
    string fileLine;
    
    int theID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
    thePQ -> ~PQueue();
    
    ifstream inFile;
    inFile.open(currentDocPath.mb_str(), ios::in);
    
    if (!inFile) {
        mainEditBox->AppendText("\n\n\nAin't no data in here..\n\n");
        return;
    }
    
    while (!inFile.eof()) {
        getline(inFile, fileLine, '\n');
        
        istringstream ss(fileLine);
        getline(ss, record, ' ');
        inFile >> theID;
        inFile.ignore(',', '\t');
        inFile >> fName;
        inFile >> lName;
        inFile >> destination >> season;
        inFile >> booking;
        cout << theID << endl;
        
        thePQ->push_back(theID, fName, lName, destination, season, booking);
        record = makeTheRecord(theID, fName, lName, destination, season, booking);
        record.append("\n");
        
        
        
        
        
        
        wxString wxRecord(record.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxRecord);
        
        record = "";
        
        
        
        
    }
    inFile.close();
}

void MyFrame::OnPQAddData(wxCommandEvent& WXUNUSED (event )) {
    mainEditBox->Clear();
    
    
    vacationRecord data;
    Dialog *datadialog = new Dialog( wxT("Data Entry for Queue"),
                                    wxPoint(200,200), wxSize(420,420) );
    if (datadialog->ShowModal() == wxID_OK) {
        data.ID = datadialog-> idEditBox->GetValue();
        data.fName = datadialog -> firstNameEditBox->GetValue();
        data.lName = datadialog -> lastNameEditBox->GetValue();
        data.destination = datadialog -> destinationEditBox->GetValue();
        data.booking = datadialog -> bookingEditBox->GetValue();
        data.season = datadialog -> seasonCombo->GetValue();
        
        mainEditBox->Clear();
        
        int ID =to_int(string(data.ID.mb_str()));
        string fName = string(data.fName.mb_str());
        string lName = string(data.lName.mb_str());
        string destination = string(data.destination.mb_str());
        string booking = string(data.booking.mb_str());
        string season = string(data.season.mb_str());
        
        mainEditBox->AppendText(getRecord(data));
        thePQ -> push_back(ID, fName, lName, destination, season, booking);
    }
    
    else {
        datadialog -> Close();
        
    }
    datadialog -> Destroy();
}


void MyFrame::OnPQDisplayAll(wxCommandEvent& WXUNUSED (event )) {
    mainEditBox->Clear();
    
    
    string all = thePQ->display();
    string record = all;
    if (all.size() == 0)
        mainEditBox->AppendText(wxT("\n\n\t\tThe Queue is empty!\n"));
    else
    {
        
        
        
        
        wxString wxRecords(all.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Records of the Queue*****\n\n"));
        mainEditBox->AppendText(wxRecords);
    }
    
}

void MyFrame::OnPQShowHead(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    string head = thePQ->highestPriority();
    
    string record = head;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Head of the Deque*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPQShowTail(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    string tail = thePQ->end();
    
    string record = tail;
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Head of the Deque*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPQDequeue(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    string del = thePQ->pop_front();
    string record = del;
    
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Removed Record*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

//===================================================================================\\
//=========== Definitions for the Stack Functions ===================================\\
//===================================================================================\\

void MyFrame::OnCreateStack(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox -> Clear();
    
    string record;
    string theRecord;
    string fileLine;
    
    int theID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
    theStack -> ~stack();
    
    ifstream inFile;
    inFile.open(currentDocPath.mb_str(), ios::in);
    
    if (!inFile) {
        mainEditBox->AppendText("\n\n\nAin't no data in here..\n\n");
        return;
    }
    
    while (!inFile.eof()) {
        getline(inFile, fileLine, '\n');
        
        istringstream ss(fileLine);
        getline(ss, record, ' ');
        inFile >> theID;
        inFile.ignore(',', '\t');
        inFile >> fName;
        inFile >> lName;
        inFile >> destination >> season;
        inFile >> booking;
        cout << season << endl;
        
        if (season == "Spring,") {
        theStack->push(theID, fName, lName, destination, season, booking);
        record = makeTheRecord(theID, fName, lName, destination, season, booking);
        record.append("\n");
            wxString wxRecord(record.c_str(), wxConvUTF8);
            mainEditBox->AppendText(wxRecord);
            
            record = "";
        }
        
        
        
        
        
        
        
        
        
        
    }
    inFile.close();
}

void MyFrame::OnPush(wxCommandEvent& WXUNUSED ( event )) {
mainEditBox->Clear();


vacationRecord data;
Dialog *datadialog = new Dialog( wxT("Data Entry for Queue"),
                                wxPoint(200,200), wxSize(420,420) );
if (datadialog->ShowModal() == wxID_OK) {
    data.ID = datadialog-> idEditBox->GetValue();
    data.fName = datadialog -> firstNameEditBox->GetValue();
    data.lName = datadialog -> lastNameEditBox->GetValue();
    data.destination = datadialog -> destinationEditBox->GetValue();
    data.booking = datadialog -> bookingEditBox->GetValue();
    data.season = datadialog -> seasonCombo->GetValue();
    
    mainEditBox->Clear();
    
    int ID =to_int(string(data.ID.mb_str()));
    string fName = string(data.fName.mb_str());
    string lName = string(data.lName.mb_str());
    string destination = string(data.destination.mb_str());
    string booking = string(data.booking.mb_str());
    string season = string(data.season.mb_str());
    
    mainEditBox->AppendText(getRecord(data));
    theStack -> push(ID, fName, lName, destination, season, booking);
}

else {
    datadialog -> Close();
    
}
datadialog -> Destroy();
}

void MyFrame::OnPop(wxCommandEvent& WXUNUSED ( event )) {
    mainEditBox->Clear();
    
    string del = theStack->pop();
    string record = del;
    
    wxString wxRecord(record.c_str(), wxConvUTF8);
    mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Removed Record*****\n\n"));
    mainEditBox->AppendText(wxRecord);
}

void MyFrame::OnStackDisplayAll(wxCommandEvent& WXUNUSED (event)) {
    mainEditBox->Clear();
    
    
    string all = theStack->displayStack();
    string record = all;
    if (all.size() == 0)
        mainEditBox->AppendText(wxT("\n\n\t\tThe Queue is empty!\n"));
    else
    {
        
        
        
        
        wxString wxRecords(all.c_str(), wxConvUTF8);
        mainEditBox->AppendText(wxT("\n\t\t*****Displaying the Records of the Queue*****\n\n"));
        mainEditBox->AppendText(wxRecords);
    }
}

void MyFrame::OnHelp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxMessageBox(wxT("HELP!!!"), wxT("Minimal Help"), 
                     wxOK | wxCANCEL | wxICON_QUESTION, this);
    }
