#include "wxlogoutput.h"
#include "wmlogevent.h"
#include <wx/log.h>
void wxLogOutput::Flush(int nLogLevel, const std::stringstream&  logStream)
{
    wxLogDebug(wxString::FromAscii(logStream.str().c_str()));
//    wxString sLog(wxString::FromAscii(logStream.str().c_str()));
//    sLog.Replace(wxT("\n"), wxT(""));
//
//    wmLog::Get()->Log(sLog);
}
