//tts_module.cpp
#include "tts_module.h"
#include <sphelper.h>

ttsModule::ttsModule()
{
    pSpVoice = NULL;
}

ttsModule::~ttsModule()
{

}

int  ttsModule::Initialise()
{
    pSpVoice = NULL;
    // Initialize COM
    CoInitialize(NULL);

    // Create the voice interface object
    if (FAILED(CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&pSpVoice)))
    {
        printf("Fail to create instance of ISpVoice!");
        return -1;
    }

    CComPtr<IEnumSpObjectTokens> cpEnum;
    CComPtr<ISpObjectToken> cpToken;

    //if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Ekho Mandarin", NULL, &cpEnum)))
    //if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Microsoft Lili", NULL, &cpEnum)))
    if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Microsoft Haruka Desktop", NULL, &cpEnum)))
    {
        printf("Fail to get voices!");
        return -2;
    }

    //Get the closest token
    if (FAILED(cpEnum->Next(1, &cpToken, NULL)))
    {
        printf("Fail to get voice EkhoVoice!");
        return -3;
    }

    //set the voice 
    if (FAILED(((ISpVoice*)pSpVoice)->SetVoice(cpToken)))
    {
        printf("Fail to set voice EkhoVoice!");
        return -4;
    }

    return 0;
}

int ttsModule::Readout(const char* text)
{
    int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, text, -1, NULL, 0);
    if (nLen == 0)
    {
        printf("MultiByteToWideChar get length = 0");
        return -1;
    }
    wchar_t* pResult = new wchar_t[nLen];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, text, -1, pResult, nLen);

    ((ISpVoice*)pSpVoice)->Speak(pResult, SPF_DEFAULT, NULL);
    delete[] pResult;
    return 0;
}

void ttsModule::Uninitialise()
{
    CoUninitialize();
}
