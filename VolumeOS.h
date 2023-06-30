/*#ifndef VOLUMEOS_H
#define VOLUMEOS_H


#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>
#pragma comment(lib, "ole32.lib") //extern


//Управление звуком
class VolumeOS
{
public:
    HRESULT hr;
    bool decibels;
    bool scalar;
    double Volume;

    VolumeOS()
    {
        hr=NULL;
        decibels = false;
        scalar = false;
        CoInitialize(NULL);
        //newVolume=nVolume;
    }



    bool VolumeSET(double nVolume,bool bScalar)
    {
        double newVolume = nVolume;
        Volume = newVolume;
        IMMDeviceEnumerator *deviceEnumerator = NULL;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
                              __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
        IMMDevice *defaultDevice = NULL;

        hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
        deviceEnumerator->Release();
        deviceEnumerator = NULL;

        IAudioEndpointVolume *endpointVolume = NULL;
        hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
             CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
        defaultDevice->Release();
        defaultDevice = NULL;

        // -------------------------
        float currentVolume = 0;
        endpointVolume->GetMasterVolumeLevel(&currentVolume);
        //printf("Current volume in dB is: %f\n", currentVolume);

        hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
        //CString strCur=L"";
        //strCur.Format(L"%f",currentVolume);
        //AfxMessageBox(strCur);

        // printf("Current volume as a scalar is: %f\n", currentVolume);
        if (bScalar==false)
        {
            hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
        }
        else if (bScalar==true)
        {
            hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
        }
        endpointVolume->Release();



        return FALSE;
    }

};

#endif // VOLUMEOS_H*/
