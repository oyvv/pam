#include "ptppanel.h"
#include "ptpbuilder.h"
#include "timedbuffer.h"
#include "session.h"
#include "wxptp.h"

//(*InternalHeaders(ptpPanel)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(ptpPanel)
const long ptpPanel::ID_M_PLST1 = wxNewId();
const long ptpPanel::ID_M_PLBL1 = wxNewId();
const long ptpPanel::ID_M_PLBL2 = wxNewId();
const long ptpPanel::ID_M_PLBL3 = wxNewId();
const long ptpPanel::ID_M_PLBL12 = wxNewId();
const long ptpPanel::ID_M_PLBL13 = wxNewId();
const long ptpPanel::ID_M_PLBL14 = wxNewId();
const long ptpPanel::ID_M_PLBL30 = wxNewId();
const long ptpPanel::ID_M_PLBL24 = wxNewId();
const long ptpPanel::ID_M_PLBL25 = wxNewId();
const long ptpPanel::ID_M_PLBL26 = wxNewId();
const long ptpPanel::ID_M_PLBL27 = wxNewId();
const long ptpPanel::ID_M_PLBL4 = wxNewId();
const long ptpPanel::ID_M_PLBL15 = wxNewId();
const long ptpPanel::ID_M_PLBL5 = wxNewId();
const long ptpPanel::ID_M_PLBL16 = wxNewId();
const long ptpPanel::ID_M_PLBL7 = wxNewId();
const long ptpPanel::ID_M_PLBL17 = wxNewId();
const long ptpPanel::ID_M_PLBL8 = wxNewId();
const long ptpPanel::ID_M_PLBL18 = wxNewId();
const long ptpPanel::ID_M_PLBL9 = wxNewId();
const long ptpPanel::ID_M_PLBL19 = wxNewId();
const long ptpPanel::ID_M_PLBL6 = wxNewId();
const long ptpPanel::ID_M_PLBL20 = wxNewId();
const long ptpPanel::ID_M_PLBL11 = wxNewId();
const long ptpPanel::ID_M_PLBL21 = wxNewId();
const long ptpPanel::ID_M_PLBL10 = wxNewId();
const long ptpPanel::ID_M_PLBL22 = wxNewId();
const long ptpPanel::ID_PANEL1 = wxNewId();
const long ptpPanel::ID_M_PLBL23 = wxNewId();
const long ptpPanel::ID_M_PLBL31 = wxNewId();
const long ptpPanel::ID_M_PLBL32 = wxNewId();
const long ptpPanel::ID_M_PLBL33 = wxNewId();
const long ptpPanel::ID_M_PLBL34 = wxNewId();
const long ptpPanel::ID_M_PLBL35 = wxNewId();
const long ptpPanel::ID_PANEL2 = wxNewId();
const long ptpPanel::ID_M_PLBL28 = wxNewId();
const long ptpPanel::ID_M_PLBL29 = wxNewId();
const long ptpPanel::ID_M_PLBL36 = wxNewId();
const long ptpPanel::ID_M_PLBL37 = wxNewId();
const long ptpPanel::ID_M_PLBL38 = wxNewId();
const long ptpPanel::ID_M_PLBL39 = wxNewId();
const long ptpPanel::ID_PANEL3 = wxNewId();
const long ptpPanel::ID_PANEL5 = wxNewId();
const long ptpPanel::ID_M_PLBL40 = wxNewId();
const long ptpPanel::ID_M_PLBL41 = wxNewId();
const long ptpPanel::ID_M_PLBL42 = wxNewId();
const long ptpPanel::ID_M_PLBL43 = wxNewId();
const long ptpPanel::ID_M_PLBL44 = wxNewId();
const long ptpPanel::ID_M_PLBL45 = wxNewId();
const long ptpPanel::ID_M_PLBL46 = wxNewId();
const long ptpPanel::ID_M_PLBL47 = wxNewId();
const long ptpPanel::ID_PANEL4 = wxNewId();
const long ptpPanel::ID_M_PLBL48 = wxNewId();
const long ptpPanel::ID_M_PLBL49 = wxNewId();
const long ptpPanel::ID_M_PLBL50 = wxNewId();
const long ptpPanel::ID_M_PLBL51 = wxNewId();
const long ptpPanel::ID_M_PLBL52 = wxNewId();
const long ptpPanel::ID_M_PLBL53 = wxNewId();
const long ptpPanel::ID_PANEL7 = wxNewId();
const long ptpPanel::ID_PANEL6 = wxNewId();
const long ptpPanel::ID_M_PSWP1 = wxNewId();
const long ptpPanel::ID_M_PLBL54 = wxNewId();
const long ptpPanel::ID_M_PLBL55 = wxNewId();
const long ptpPanel::ID_M_PLBL56 = wxNewId();
const long ptpPanel::ID_M_PLBL57 = wxNewId();
const long ptpPanel::ID_M_PLBL61 = wxNewId();
const long ptpPanel::ID_M_PLBL58 = wxNewId();
const long ptpPanel::ID_M_PLBL62 = wxNewId();
const long ptpPanel::ID_M_PLBL59 = wxNewId();
const long ptpPanel::ID_M_PLBL63 = wxNewId();
const long ptpPanel::ID_M_PLBL60 = wxNewId();
const long ptpPanel::ID_M_PLBL64 = wxNewId();
const long ptpPanel::ID_PANEL8 = wxNewId();
//*)

wxIMPLEMENT_DYNAMIC_CLASS(ptpPanel, pmPanel)

BEGIN_EVENT_TABLE(ptpPanel,pmPanel)
	//(*EventTable(ptpPanel)
	//*)
END_EVENT_TABLE()


ptpPanel::ptpPanel(wxWindow* parent,ptpBuilder* pBuilder, wxWindowID id,const wxPoint& pos,const wxSize& size) : pmPanel(),
    m_pBuilder(pBuilder),
    m_nDomain(0)
{
	//(*Initialize(ptpPanel)
	Create(parent, id, wxDefaultPosition, wxSize(800,480), wxTAB_TRAVERSAL, _T("id"));
	SetBackgroundColour(wxColour(0,0,0));
	m_plstClocks = new wmList(this, ID_M_PLST1, wxPoint(0,0), wxSize(150,480), wmList::STYLE_SELECT, 1, wxSize(-1,-1), 1, wxSize(-1,-1));
	m_plstClocks->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	m_plstClocks->SetButtonColour(wxColour(wxT("#000000")));
	m_plstClocks->SetSelectedButtonColour(wxColour(wxT("#FF8000")));
	m_ptitleIdentity = new wmLabel(this, ID_M_PLBL1, _("Port Identitiy"), wxPoint(160,0), wxSize(100,30), 0, _T("ID_M_PLBL1"));
	m_ptitleIdentity->SetBorderState(uiRect::BORDER_FLAT);
	m_ptitleIdentity->GetUiRect().SetGradient(wxWEST);
	m_ptitleIdentity->SetForegroundColour(wxColour(255,255,255));
	m_ptitleIdentity->SetBackgroundColour(wxColour(92,122,224));
	m_ptitleAddress = new wmLabel(this, ID_M_PLBL2, _("Address"), wxPoint(160,35), wxSize(100,30), 0, _T("ID_M_PLBL2"));
	m_ptitleAddress->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleAddress->GetUiRect().SetGradient(wxWEST);
	m_ptitleAddress->SetForegroundColour(wxColour(255,255,255));
	m_ptitleAddress->SetBackgroundColour(wxColour(92,122,224));
	m_ptitleState = new wmLabel(this, ID_M_PLBL3, _("State"), wxPoint(160,70), wxSize(100,30), 0, _T("ID_M_PLBL3"));
	m_ptitleState->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleState->GetUiRect().SetGradient(wxWEST);
	m_ptitleState->SetForegroundColour(wxColour(255,255,255));
	m_ptitleState->SetBackgroundColour(wxColour(92,122,224));
	m_plblIdentity = new wmLabel(this, ID_M_PLBL12, wxEmptyString, wxPoint(260,0), wxSize(200,30), 0, _T("ID_M_PLBL12"));
	m_plblIdentity->SetBorderState(uiRect::BORDER_DOWN);
	m_plblIdentity->GetUiRect().SetGradient(0);
	m_plblIdentity->SetForegroundColour(wxColour(0,0,0));
	m_plblIdentity->SetBackgroundColour(wxColour(255,255,255));
	m_pblAddress = new wmLabel(this, ID_M_PLBL13, wxEmptyString, wxPoint(260,35), wxSize(200,30), 0, _T("ID_M_PLBL13"));
	m_pblAddress->SetBorderState(uiRect::BORDER_DOWN);
	m_pblAddress->GetUiRect().SetGradient(0);
	m_pblAddress->SetForegroundColour(wxColour(0,0,0));
	m_pblAddress->SetBackgroundColour(wxColour(255,255,255));
	m_plblState = new wmLabel(this, ID_M_PLBL14, wxEmptyString, wxPoint(260,70), wxSize(200,30), 0, _T("ID_M_PLBL14"));
	m_plblState->SetBorderState(uiRect::BORDER_DOWN);
	m_plblState->GetUiRect().SetGradient(0);
	m_plblState->SetForegroundColour(wxColour(0,0,0));
	m_plblState->SetBackgroundColour(wxColour(255,255,255));
	m_ppnlAnnouncements = new wxPanel(this, ID_PANEL1, wxPoint(160,105), wxSize(300,360), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	m_ppnlAnnouncements->SetBackgroundColour(wxColour(0,0,0));
	m_ptitleAnnouncements = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL30, _("Announcements"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL30"));
	m_ptitleAnnouncements->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleAnnouncements->GetUiRect().SetGradient(wxWEST);
	m_ptitleAnnouncements->SetForegroundColour(wxColour(255,255,255));
	m_ptitleAnnouncements->SetBackgroundColour(wxColour(98,219,101));
	wxFont m_ptitleAnnouncementsFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_ptitleAnnouncements->SetFont(m_ptitleAnnouncementsFont);
	m_ptitleAnnRate = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL24, _("Rate"), wxPoint(0,35), wxSize(50,30), 0, _T("ID_M_PLBL24"));
	m_ptitleAnnRate->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleAnnRate->GetUiRect().SetGradient(wxWEST);
	m_ptitleAnnRate->SetForegroundColour(wxColour(255,255,255));
	m_ptitleAnnRate->SetBackgroundColour(wxColour(92,122,224));
	m_plblAnnRate = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL25, wxEmptyString, wxPoint(50,35), wxSize(50,30), 0, _T("ID_M_PLBL25"));
	m_plblAnnRate->SetBorderState(uiRect::BORDER_DOWN);
	m_plblAnnRate->GetUiRect().SetGradient(0);
	m_plblAnnRate->SetForegroundColour(wxColour(0,0,0));
	m_plblAnnRate->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleCount = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL26, _("Count"), wxPoint(100,35), wxSize(50,30), 0, _T("ID_M_PLBL26"));
	m_ptitleCount->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleCount->GetUiRect().SetGradient(wxWEST);
	m_ptitleCount->SetForegroundColour(wxColour(255,255,255));
	m_ptitleCount->SetBackgroundColour(wxColour(92,122,224));
	m_plblAnnCount = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL27, wxEmptyString, wxPoint(150,35), wxSize(150,30), 0, _T("ID_M_PLBL27"));
	m_plblAnnCount->SetBorderState(uiRect::BORDER_DOWN);
	m_plblAnnCount->GetUiRect().SetGradient(0);
	m_plblAnnCount->SetForegroundColour(wxColour(0,0,0));
	m_plblAnnCount->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleUtc = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL4, _("UTC Offset"), wxPoint(0,70), wxSize(100,30), 0, _T("ID_M_PLBL4"));
	m_ptitleUtc->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleUtc->GetUiRect().SetGradient(wxWEST);
	m_ptitleUtc->SetForegroundColour(wxColour(255,255,255));
	m_ptitleUtc->SetBackgroundColour(wxColour(92,122,224));
	m_plblUTC = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL15, wxEmptyString, wxPoint(100,70), wxSize(200,30), 0, _T("ID_M_PLBL15"));
	m_plblUTC->SetBorderState(uiRect::BORDER_DOWN);
	m_plblUTC->GetUiRect().SetGradient(0);
	m_plblUTC->SetForegroundColour(wxColour(0,0,0));
	m_plblUTC->SetBackgroundColour(wxColour(255,255,255));
	m_ptitlePriority1 = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL5, _("Priority 1"), wxPoint(0,105), wxSize(100,30), 0, _T("ID_M_PLBL5"));
	m_ptitlePriority1->SetBorderState(uiRect::BORDER_NONE);
	m_ptitlePriority1->GetUiRect().SetGradient(wxWEST);
	m_ptitlePriority1->SetForegroundColour(wxColour(255,255,255));
	m_ptitlePriority1->SetBackgroundColour(wxColour(92,122,224));
	m_plblPriority1 = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL16, wxEmptyString, wxPoint(100,105), wxSize(200,30), 0, _T("ID_M_PLBL16"));
	m_plblPriority1->SetBorderState(uiRect::BORDER_DOWN);
	m_plblPriority1->GetUiRect().SetGradient(0);
	m_plblPriority1->SetForegroundColour(wxColour(0,0,0));
	m_plblPriority1->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleClass = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL7, _("Class"), wxPoint(0,140), wxSize(100,30), 0, _T("ID_M_PLBL7"));
	m_ptitleClass->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleClass->GetUiRect().SetGradient(wxWEST);
	m_ptitleClass->SetForegroundColour(wxColour(255,255,255));
	m_ptitleClass->SetBackgroundColour(wxColour(92,122,224));
	m_plblClass = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL17, wxEmptyString, wxPoint(100,140), wxSize(200,30), 0, _T("ID_M_PLBL17"));
	m_plblClass->SetBorderState(uiRect::BORDER_DOWN);
	m_plblClass->GetUiRect().SetGradient(0);
	m_plblClass->SetForegroundColour(wxColour(0,0,0));
	m_plblClass->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleAccuracy = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL8, _("Accuracy"), wxPoint(0,175), wxSize(100,30), 0, _T("ID_M_PLBL8"));
	m_ptitleAccuracy->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleAccuracy->GetUiRect().SetGradient(wxWEST);
	m_ptitleAccuracy->SetForegroundColour(wxColour(255,255,255));
	m_ptitleAccuracy->SetBackgroundColour(wxColour(92,122,224));
	m_plblAccuracy = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL18, wxEmptyString, wxPoint(100,175), wxSize(200,30), 0, _T("ID_M_PLBL18"));
	m_plblAccuracy->SetBorderState(uiRect::BORDER_DOWN);
	m_plblAccuracy->GetUiRect().SetGradient(0);
	m_plblAccuracy->SetForegroundColour(wxColour(0,0,0));
	m_plblAccuracy->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleVariance = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL9, _("Variance"), wxPoint(0,210), wxSize(100,30), 0, _T("ID_M_PLBL9"));
	m_ptitleVariance->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleVariance->GetUiRect().SetGradient(wxWEST);
	m_ptitleVariance->SetForegroundColour(wxColour(255,255,255));
	m_ptitleVariance->SetBackgroundColour(wxColour(92,122,224));
	m_plblVariance = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL19, wxEmptyString, wxPoint(100,210), wxSize(200,30), 0, _T("ID_M_PLBL19"));
	m_plblVariance->SetBorderState(uiRect::BORDER_DOWN);
	m_plblVariance->GetUiRect().SetGradient(0);
	m_plblVariance->SetForegroundColour(wxColour(0,0,0));
	m_plblVariance->SetBackgroundColour(wxColour(255,255,255));
	m_ptitlePriority2 = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL6, _("Priority 2"), wxPoint(0,245), wxSize(100,30), 0, _T("ID_M_PLBL6"));
	m_ptitlePriority2->SetBorderState(uiRect::BORDER_NONE);
	m_ptitlePriority2->GetUiRect().SetGradient(wxWEST);
	m_ptitlePriority2->SetForegroundColour(wxColour(255,255,255));
	m_ptitlePriority2->SetBackgroundColour(wxColour(92,122,224));
	m_plblPriority2 = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL20, wxEmptyString, wxPoint(100,245), wxSize(200,30), 0, _T("ID_M_PLBL20"));
	m_plblPriority2->SetBorderState(uiRect::BORDER_DOWN);
	m_plblPriority2->GetUiRect().SetGradient(0);
	m_plblPriority2->SetForegroundColour(wxColour(0,0,0));
	m_plblPriority2->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleSteps = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL11, _("Steps Removed"), wxPoint(0,280), wxSize(100,30), 0, _T("ID_M_PLBL11"));
	m_ptitleSteps->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleSteps->GetUiRect().SetGradient(wxWEST);
	m_ptitleSteps->SetForegroundColour(wxColour(255,255,255));
	m_ptitleSteps->SetBackgroundColour(wxColour(92,122,224));
	m_plblSteps = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL21, wxEmptyString, wxPoint(100,280), wxSize(200,30), 0, _T("ID_M_PLBL21"));
	m_plblSteps->SetBorderState(uiRect::BORDER_DOWN);
	m_plblSteps->GetUiRect().SetGradient(0);
	m_plblSteps->SetForegroundColour(wxColour(0,0,0));
	m_plblSteps->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleSource = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL10, _("Time Souce"), wxPoint(0,315), wxSize(100,30), 0, _T("ID_M_PLBL10"));
	m_ptitleSource->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleSource->GetUiRect().SetGradient(wxWEST);
	m_ptitleSource->SetForegroundColour(wxColour(255,255,255));
	m_ptitleSource->SetBackgroundColour(wxColour(92,122,224));
	m_plblSource = new wmLabel(m_ppnlAnnouncements, ID_M_PLBL22, wxEmptyString, wxPoint(100,315), wxSize(200,30), 0, _T("ID_M_PLBL22"));
	m_plblSource->SetBorderState(uiRect::BORDER_DOWN);
	m_plblSource->GetUiRect().SetGradient(0);
	m_plblSource->SetForegroundColour(wxColour(0,0,0));
	m_plblSource->SetBackgroundColour(wxColour(255,255,255));
	m_pswp = new wmSwitcherPanel(this, ID_M_PSWP1, wxPoint(470,0), wxSize(300,245), wmSwitcherPanel::STYLE_NOSWIPE|wmSwitcherPanel::STYLE_NOANIMATION, _T("ID_M_PSWP1"));
	m_pswp->SetPageNameStyle(0);
	m_pswp->SetBackgroundColour(wxColour(0,0,0));
	m_ppnlMaster = new wxPanel(m_pswp, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	m_ppnlMaster->SetBackgroundColour(wxColour(0,0,0));
	m_ppnlSync = new wxPanel(m_ppnlMaster, ID_PANEL2, wxPoint(0,0), wxSize(300,105), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	m_ppnlSync->SetBackgroundColour(wxColour(0,0,0));
	m_ptitleSync = new wmLabel(m_ppnlSync, ID_M_PLBL23, _("Sync"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL23"));
	m_ptitleSync->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleSync->GetUiRect().SetGradient(wxWEST);
	m_ptitleSync->SetForegroundColour(wxColour(255,255,255));
	m_ptitleSync->SetBackgroundColour(wxColour(98,219,101));
	wxFont m_ptitleSyncFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_ptitleSync->SetFont(m_ptitleSyncFont);
	m_ptitleSyncRate = new wmLabel(m_ppnlSync, ID_M_PLBL31, _("Rate"), wxPoint(0,35), wxSize(50,30), 0, _T("ID_M_PLBL31"));
	m_ptitleSyncRate->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleSyncRate->GetUiRect().SetGradient(wxWEST);
	m_ptitleSyncRate->SetForegroundColour(wxColour(255,255,255));
	m_ptitleSyncRate->SetBackgroundColour(wxColour(92,122,224));
	m_plblSyncRate = new wmLabel(m_ppnlSync, ID_M_PLBL32, wxEmptyString, wxPoint(50,35), wxSize(50,30), 0, _T("ID_M_PLBL32"));
	m_plblSyncRate->SetBorderState(uiRect::BORDER_DOWN);
	m_plblSyncRate->GetUiRect().SetGradient(0);
	m_plblSyncRate->SetForegroundColour(wxColour(0,0,0));
	m_plblSyncRate->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleSyncCount = new wmLabel(m_ppnlSync, ID_M_PLBL33, _("Count"), wxPoint(100,35), wxSize(50,30), 0, _T("ID_M_PLBL33"));
	m_ptitleSyncCount->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleSyncCount->GetUiRect().SetGradient(wxWEST);
	m_ptitleSyncCount->SetForegroundColour(wxColour(255,255,255));
	m_ptitleSyncCount->SetBackgroundColour(wxColour(92,122,224));
	m_plblSyncCount = new wmLabel(m_ppnlSync, ID_M_PLBL34, wxEmptyString, wxPoint(150,35), wxSize(150,30), 0, _T("ID_M_PLBL34"));
	m_plblSyncCount->SetBorderState(uiRect::BORDER_DOWN);
	m_plblSyncCount->GetUiRect().SetGradient(0);
	m_plblSyncCount->SetForegroundColour(wxColour(0,0,0));
	m_plblSyncCount->SetBackgroundColour(wxColour(255,255,255));
	m_plblSyncMessage = new wmLabel(m_ppnlSync, ID_M_PLBL35, wxEmptyString, wxPoint(0,70), wxSize(300,30), 0, _T("ID_M_PLBL35"));
	m_plblSyncMessage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblSyncMessage->GetUiRect().SetGradient(0);
	m_plblSyncMessage->SetForegroundColour(wxColour(0,0,0));
	m_plblSyncMessage->SetBackgroundColour(wxColour(255,255,255));
	m_ppnlFollowUp = new wxPanel(m_ppnlMaster, ID_PANEL3, wxPoint(0,105), wxSize(300,105), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	m_ppnlFollowUp->SetBackgroundColour(wxColour(0,0,0));
	m_ptitleFollowUp = new wmLabel(m_ppnlFollowUp, ID_M_PLBL28, _("Follow Up"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL28"));
	m_ptitleFollowUp->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleFollowUp->GetUiRect().SetGradient(wxWEST);
	m_ptitleFollowUp->SetForegroundColour(wxColour(255,255,255));
	m_ptitleFollowUp->SetBackgroundColour(wxColour(98,219,101));
	wxFont m_ptitleFollowUpFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_ptitleFollowUp->SetFont(m_ptitleFollowUpFont);
	m_ptitleFollowRate = new wmLabel(m_ppnlFollowUp, ID_M_PLBL29, _("Rate"), wxPoint(0,35), wxSize(50,30), 0, _T("ID_M_PLBL29"));
	m_ptitleFollowRate->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleFollowRate->GetUiRect().SetGradient(wxWEST);
	m_ptitleFollowRate->SetForegroundColour(wxColour(255,255,255));
	m_ptitleFollowRate->SetBackgroundColour(wxColour(92,122,224));
	m_plblFollowRate = new wmLabel(m_ppnlFollowUp, ID_M_PLBL36, wxEmptyString, wxPoint(50,35), wxSize(50,30), 0, _T("ID_M_PLBL36"));
	m_plblFollowRate->SetBorderState(uiRect::BORDER_DOWN);
	m_plblFollowRate->GetUiRect().SetGradient(0);
	m_plblFollowRate->SetForegroundColour(wxColour(0,0,0));
	m_plblFollowRate->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleFollowCount = new wmLabel(m_ppnlFollowUp, ID_M_PLBL37, _("Count"), wxPoint(100,35), wxSize(50,30), 0, _T("ID_M_PLBL37"));
	m_ptitleFollowCount->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleFollowCount->GetUiRect().SetGradient(wxWEST);
	m_ptitleFollowCount->SetForegroundColour(wxColour(255,255,255));
	m_ptitleFollowCount->SetBackgroundColour(wxColour(92,122,224));
	m_plblFollowCount = new wmLabel(m_ppnlFollowUp, ID_M_PLBL38, wxEmptyString, wxPoint(150,35), wxSize(150,30), 0, _T("ID_M_PLBL38"));
	m_plblFollowCount->SetBorderState(uiRect::BORDER_DOWN);
	m_plblFollowCount->GetUiRect().SetGradient(0);
	m_plblFollowCount->SetForegroundColour(wxColour(0,0,0));
	m_plblFollowCount->SetBackgroundColour(wxColour(255,255,255));
	m_plblFollowMessage = new wmLabel(m_ppnlFollowUp, ID_M_PLBL39, wxEmptyString, wxPoint(0,70), wxSize(300,30), 0, _T("ID_M_PLBL39"));
	m_plblFollowMessage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblFollowMessage->GetUiRect().SetGradient(0);
	m_plblFollowMessage->SetForegroundColour(wxColour(0,0,0));
	m_plblFollowMessage->SetBackgroundColour(wxColour(255,255,255));
	m_ppnlSlave = new wxPanel(m_pswp, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	m_ppnlSlave->SetBackgroundColour(wxColour(0,0,0));
	m_ppnlRequests = new wxPanel(m_ppnlSlave, ID_PANEL4, wxPoint(0,0), wxSize(300,140), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	m_ppnlRequests->SetBackgroundColour(wxColour(0,0,0));
	m_ptitleDelay = new wmLabel(m_ppnlRequests, ID_M_PLBL40, _("Delay Requests"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL40"));
	m_ptitleDelay->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelay->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelay->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelay->SetBackgroundColour(wxColour(98,219,101));
	wxFont m_ptitleDelayFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_ptitleDelay->SetFont(m_ptitleDelayFont);
	m_ptitleDelayRate = new wmLabel(m_ppnlRequests, ID_M_PLBL41, _("Rate"), wxPoint(0,35), wxSize(50,30), 0, _T("ID_M_PLBL41"));
	m_ptitleDelayRate->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelayRate->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelayRate->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelayRate->SetBackgroundColour(wxColour(92,122,224));
	m_plblDelayRate = new wmLabel(m_ppnlRequests, ID_M_PLBL42, wxEmptyString, wxPoint(50,35), wxSize(50,30), 0, _T("ID_M_PLBL42"));
	m_plblDelayRate->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayRate->GetUiRect().SetGradient(0);
	m_plblDelayRate->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayRate->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleDelayCount = new wmLabel(m_ppnlRequests, ID_M_PLBL43, _("Count"), wxPoint(100,35), wxSize(50,30), 0, _T("ID_M_PLBL43"));
	m_ptitleDelayCount->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelayCount->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelayCount->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelayCount->SetBackgroundColour(wxColour(92,122,224));
	m_plblDelayCount = new wmLabel(m_ppnlRequests, ID_M_PLBL44, wxEmptyString, wxPoint(150,35), wxSize(150,30), 0, _T("ID_M_PLBL44"));
	m_plblDelayCount->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayCount->GetUiRect().SetGradient(0);
	m_plblDelayCount->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayCount->SetBackgroundColour(wxColour(255,255,255));
	m_plblDelayMessage = new wmLabel(m_ppnlRequests, ID_M_PLBL45, wxEmptyString, wxPoint(0,70), wxSize(300,30), 0, _T("ID_M_PLBL45"));
	m_plblDelayMessage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayMessage->GetUiRect().SetGradient(0);
	m_plblDelayMessage->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayMessage->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleDelayMech = new wmLabel(m_ppnlRequests, ID_M_PLBL46, _("Mechanism"), wxPoint(0,105), wxSize(100,30), 0, _T("ID_M_PLBL46"));
	m_ptitleDelayMech->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelayMech->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelayMech->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelayMech->SetBackgroundColour(wxColour(92,122,224));
	m_plblDelayMech = new wmLabel(m_ppnlRequests, ID_M_PLBL47, wxEmptyString, wxPoint(100,105), wxSize(200,30), 0, _T("ID_M_PLBL47"));
	m_plblDelayMech->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayMech->GetUiRect().SetGradient(0);
	m_plblDelayMech->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayMech->SetBackgroundColour(wxColour(255,255,255));
	m_ppnlResponses = new wxPanel(m_ppnlSlave, ID_PANEL7, wxPoint(0,140), wxSize(300,140), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
	m_ppnlResponses->SetBackgroundColour(wxColour(0,0,0));
	m_pLbl1 = new wmLabel(m_ppnlResponses, ID_M_PLBL48, _("Delay Responses Received"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL48"));
	m_pLbl1->SetBorderState(uiRect::BORDER_NONE);
	m_pLbl1->GetUiRect().SetGradient(wxWEST);
	m_pLbl1->SetForegroundColour(wxColour(255,255,255));
	m_pLbl1->SetBackgroundColour(wxColour(98,219,101));
	wxFont m_pLbl1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_pLbl1->SetFont(m_pLbl1Font);
	m_ptitleResponseRate = new wmLabel(m_ppnlResponses, ID_M_PLBL49, _("Rate"), wxPoint(0,35), wxSize(50,30), 0, _T("ID_M_PLBL49"));
	m_ptitleResponseRate->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleResponseRate->GetUiRect().SetGradient(wxWEST);
	m_ptitleResponseRate->SetForegroundColour(wxColour(255,255,255));
	m_ptitleResponseRate->SetBackgroundColour(wxColour(92,122,224));
	m_plblResponseRate = new wmLabel(m_ppnlResponses, ID_M_PLBL50, wxEmptyString, wxPoint(50,35), wxSize(50,30), 0, _T("ID_M_PLBL50"));
	m_plblResponseRate->SetBorderState(uiRect::BORDER_DOWN);
	m_plblResponseRate->GetUiRect().SetGradient(0);
	m_plblResponseRate->SetForegroundColour(wxColour(0,0,0));
	m_plblResponseRate->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleResponseCount = new wmLabel(m_ppnlResponses, ID_M_PLBL51, _("Count"), wxPoint(100,35), wxSize(50,30), 0, _T("ID_M_PLBL51"));
	m_ptitleResponseCount->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleResponseCount->GetUiRect().SetGradient(wxWEST);
	m_ptitleResponseCount->SetForegroundColour(wxColour(255,255,255));
	m_ptitleResponseCount->SetBackgroundColour(wxColour(92,122,224));
	m_plblResponseCount = new wmLabel(m_ppnlResponses, ID_M_PLBL52, wxEmptyString, wxPoint(150,35), wxSize(150,30), 0, _T("ID_M_PLBL52"));
	m_plblResponseCount->SetBorderState(uiRect::BORDER_DOWN);
	m_plblResponseCount->GetUiRect().SetGradient(0);
	m_plblResponseCount->SetForegroundColour(wxColour(0,0,0));
	m_plblResponseCount->SetBackgroundColour(wxColour(255,255,255));
	m_plblResponseMessage = new wmLabel(m_ppnlResponses, ID_M_PLBL53, wxEmptyString, wxPoint(0,70), wxSize(300,30), 0, _T("ID_M_PLBL53"));
	m_plblResponseMessage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblResponseMessage->GetUiRect().SetGradient(0);
	m_plblResponseMessage->SetForegroundColour(wxColour(0,0,0));
	m_plblResponseMessage->SetBackgroundColour(wxColour(255,255,255));
	m_pswp->AddPage(m_ppnlMaster, _("Master"), false);
	m_pswp->AddPage(m_ppnlSlave, _("Slave"), false);
	m_ppnlLocal = new wxPanel(this, ID_PANEL8, wxPoint(470,245), wxSize(300,205), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
	m_ppnlLocal->SetBackgroundColour(wxColour(0,0,0));
	m_ptitlePam = new wmLabel(m_ppnlLocal, ID_M_PLBL54, _("PAM"), wxPoint(0,0), wxSize(300,30), 0, _T("ID_M_PLBL54"));
	m_ptitlePam->SetBorderState(uiRect::BORDER_NONE);
	m_ptitlePam->GetUiRect().SetGradient(wxWEST);
	m_ptitlePam->SetForegroundColour(wxColour(255,255,255));
	m_ptitlePam->SetBackgroundColour(wxColour(217,138,100));
	wxFont m_ptitlePamFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	m_ptitlePam->SetFont(m_ptitlePamFont);
	m_ptitleTime = new wmLabel(m_ppnlLocal, ID_M_PLBL55, _("PTP Time"), wxPoint(0,35), wxSize(100,30), 0, _T("ID_M_PLBL55"));
	m_ptitleTime->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleTime->GetUiRect().SetGradient(wxWEST);
	m_ptitleTime->SetForegroundColour(wxColour(255,255,255));
	m_ptitleTime->SetBackgroundColour(wxColour(92,122,224));
	m_plblTime = new wmLabel(m_ppnlLocal, ID_M_PLBL56, wxEmptyString, wxPoint(100,35), wxSize(200,30), 0, _T("ID_M_PLBL56"));
	m_plblTime->SetBorderState(uiRect::BORDER_DOWN);
	m_plblTime->GetUiRect().SetGradient(0);
	m_plblTime->SetForegroundColour(wxColour(0,0,0));
	m_plblTime->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleOffsetAverage = new wmLabel(m_ppnlLocal, ID_M_PLBL57, _("Offset: Average"), wxPoint(0,70), wxSize(100,30), 0, _T("ID_M_PLBL57"));
	m_ptitleOffsetAverage->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleOffsetAverage->GetUiRect().SetGradient(wxWEST);
	m_ptitleOffsetAverage->SetForegroundColour(wxColour(255,255,255));
	m_ptitleOffsetAverage->SetBackgroundColour(wxColour(92,122,224));
	m_plblOffsetAverage = new wmLabel(m_ppnlLocal, ID_M_PLBL61, wxEmptyString, wxPoint(100,70), wxSize(200,30), 0, _T("ID_M_PLBL61"));
	m_plblOffsetAverage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblOffsetAverage->GetUiRect().SetGradient(0);
	m_plblOffsetAverage->SetForegroundColour(wxColour(0,0,0));
	m_plblOffsetAverage->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleOffsetRange = new wmLabel(m_ppnlLocal, ID_M_PLBL58, _("Offset: Range"), wxPoint(0,105), wxSize(100,30), 0, _T("ID_M_PLBL58"));
	m_ptitleOffsetRange->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleOffsetRange->GetUiRect().SetGradient(wxWEST);
	m_ptitleOffsetRange->SetForegroundColour(wxColour(255,255,255));
	m_ptitleOffsetRange->SetBackgroundColour(wxColour(92,122,224));
	m_plblOffsetRange = new wmLabel(m_ppnlLocal, ID_M_PLBL62, wxEmptyString, wxPoint(100,105), wxSize(200,30), 0, _T("ID_M_PLBL62"));
	m_plblOffsetRange->SetBorderState(uiRect::BORDER_DOWN);
	m_plblOffsetRange->GetUiRect().SetGradient(0);
	m_plblOffsetRange->SetForegroundColour(wxColour(0,0,0));
	m_plblOffsetRange->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleDelayAverage = new wmLabel(m_ppnlLocal, ID_M_PLBL59, _("Delay: Average"), wxPoint(0,140), wxSize(100,30), 0, _T("ID_M_PLBL59"));
	m_ptitleDelayAverage->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelayAverage->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelayAverage->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelayAverage->SetBackgroundColour(wxColour(92,122,224));
	m_plblDelayAverage = new wmLabel(m_ppnlLocal, ID_M_PLBL63, wxEmptyString, wxPoint(100,140), wxSize(200,30), 0, _T("ID_M_PLBL63"));
	m_plblDelayAverage->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayAverage->GetUiRect().SetGradient(0);
	m_plblDelayAverage->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayAverage->SetBackgroundColour(wxColour(255,255,255));
	m_ptitleDelayRange = new wmLabel(m_ppnlLocal, ID_M_PLBL60, _("Delay: Range"), wxPoint(0,175), wxSize(100,30), 0, _T("ID_M_PLBL60"));
	m_ptitleDelayRange->SetBorderState(uiRect::BORDER_NONE);
	m_ptitleDelayRange->GetUiRect().SetGradient(wxWEST);
	m_ptitleDelayRange->SetForegroundColour(wxColour(255,255,255));
	m_ptitleDelayRange->SetBackgroundColour(wxColour(92,122,224));
	m_plblDelayRange = new wmLabel(m_ppnlLocal, ID_M_PLBL64, wxEmptyString, wxPoint(100,175), wxSize(200,30), 0, _T("ID_M_PLBL64"));
	m_plblDelayRange->SetBorderState(uiRect::BORDER_DOWN);
	m_plblDelayRange->GetUiRect().SetGradient(0);
	m_plblDelayRange->SetForegroundColour(wxColour(0,0,0));
	m_plblDelayRange->SetBackgroundColour(wxColour(255,255,255));

	Connect(ID_M_PLST1,wxEVT_LIST_SELECTED,(wxObjectEventFunction)&ptpPanel::OnlstClocksSelected);
	//*)

	Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ptpPanel::OnLeftUp);


	wxPtp::Get().AddHandler(this);

    Connect(wxID_ANY, wxEVT_CLOCK_ADDED,(wxObjectEventFunction)&ptpPanel::OnClockAdded);
    Connect(wxID_ANY, wxEVT_CLOCK_UPDATED,(wxObjectEventFunction)&ptpPanel::OnClockUpdated);
    Connect(wxID_ANY, xEVT_CLOCK_REMOVED,(wxObjectEventFunction)&ptpPanel::OnClockRemoved);
    Connect(wxID_ANY, wxEVT_CLOCK_TIME,(wxObjectEventFunction)&ptpPanel::OnClockTime);
    Connect(wxID_ANY, wxEVT_CLOCK_MASTER,(wxObjectEventFunction)&ptpPanel::OnClockMaster);
    Connect(wxID_ANY, wxEVT_CLOCK_SLAVE,(wxObjectEventFunction)&ptpPanel::OnClockSlave);

    wxPtp::Get.Run(Settings::Get().Read("AoIP_Settings", "Interface", "eth0"), m_nDomain);
	SetSize(size);
	SetPosition(pos);
}

ptpPanel::~ptpPanel()
{
	//(*Destroy(ptpPanel)
	//*)
}

void ptpPanel::SetAudioData(const timedbuffer* pBuffer)
{

}

void ptpPanel::InputSession(const session& aSession)
{

}

void ptpPanel::OutputChannels(const std::vector<char>& vChannels)
{

}


void ptpPanel::OnLeftUp(wxMouseEvent& event)
{
    m_pBuilder->Maximize((GetSize().x <= 600));
}



void ptpPanel::OnlstClocksSelected(wxCommandEvent& event)
{
    m_sSelectedClock = event.GetString();
    ShowClockDetails();
}


void ptpPanel::OnClockAdded(wxCommandEvent& event)
{
    m_plstClocks->AddButton(event.GetString());
}

void ptpPanel::OnClockUpdated(wxCommandEvent& event)
{
    if(event.GetString() == m_sSelectedClock)
    {
        ShowClockDetails();
    }
}

void ptpPanel::OnClockRemoved(wxCommandEvent& event)
{
    if(m_sSelectedClock == event.GetString())
    {
        //@todo clear clock details
    }
    m_plstClocks->DeleteButton(m_plstClocks->FindButton(event.GetString()));
}

void ptpPanel::OnClockTime(wxCommandEvent& event)
{
    if(m_sSelectedClock == event.GetString())
    {
        //@todo update the time and offset stuff
    }
}

void ptpPanel::OnClockMaster(wxCommandEvent& event)
{
    if(m_sSelectedClock == event.GetString())
    {
        m_pswp->ChangeSelection("Master");
        m_plblState = "Master";
    }
}

void ptpPanel::OnClockSlave(wxCommandEvent& event)
{
    if(m_sSelectedClock == event.GetString())
    {
        m_pswp->ChangeSelection("Slave");
        m_plblState = "Slave";
    }
}

