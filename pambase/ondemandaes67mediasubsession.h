#pragma once
#include <wx/event.h>
#include "ondemandpamsubsession.h"
#include "AudioRTPSink.hh"
#include "liveaudiosource.h"
#include <wx/thread.h>
#include <set>
class timedbuffer;


class AES67RTPSink : public AudioRTPSink
{

    public:
      static AES67RTPSink* createNew(UsageEnvironment& env, Groupsock* RTPgs);

    protected:
      AES67RTPSink(UsageEnvironment& env, Groupsock* RTPgs);
        // called only by createNew()

      virtual ~AES67RTPSink();

    private: // redefined virtual functions:

};


class OnDemandAES67MediaSubsession: public OnDemandPamSubsession
{
    public:
        static OnDemandAES67MediaSubsession* createNew(wxEvtHandler* pHandler, PamUsageEnvironment& env, unsigned char nNumChannels,LiveAudioSource::enumPacketTime ePacketTime, portNumBits initialPortNum = 5004);

        void AddSamples(const timedbuffer* pTimedBuffer);
        void FlushQueue();

        std::string GetStreamName() override
        {
            return "AES67";
        }

//        std::string GetSDP() override;


    protected: // we're a virtual base class
        OnDemandAES67MediaSubsession(wxEvtHandler* pHandler, PamUsageEnvironment& env, unsigned char nNumChannels,LiveAudioSource::enumPacketTime ePacketTime, portNumBits initialPortNum  = 5004);
        virtual ~OnDemandAES67MediaSubsession();

        // new virtual functions, defined by all subclasses
        FramedSource* createNewStreamSource(unsigned clientSessionId, unsigned& estBitrate) override;
        // "estBitrate" is the stream's estimated bitrate, in kbps
        RTPSink* createNewRTPSink(Groupsock* rtpGroupsock, unsigned char rtpPayloadTypeIfDynamic, FramedSource* inputSource) override;


        //char const* sdpLines() override;

//        int GetEpochTimestamp(RTPSink* pSink);

    private:
        wxMutex m_mutex;
        unsigned char m_nNumberOfChannels;

        LiveAudioSource::enumPacketTime m_ePacketTime;
        LiveAudioSource* m_pSource;

};

