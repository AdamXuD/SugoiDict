#ifndef  __TTS_MODULE_HH__
#define  __TTS_MODULE_HH__

#ifdef  WIN32
#ifdef  TTS_MODULE_EXPORTS
#define TTS_MODULE_API __declspec(dllexport)
#else
#define TTS_MODULE_API __declspec(dllimport)
#endif
#else
#define TTS_MODULE_API
#endif

class TTS_MODULE_API ttsModule
{
public:
    ttsModule();
    ~ttsModule();
    int  Initialise();
    int  Readout(const char* text);
    void Uninitialise();

private:
    void* pSpVoice;
};

#endif