#include <switch.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PLYR_COUNT 2

int main ()
{
	consoleInit(NULL);
    	padConfigureInput(MAX_PLYR_COUNT,HidNpadStyleSet_NpadStandard);

    	PadState pads[2];
    	padInitializeAny(&pads[0]);
	padInitializeAny(&pads[1]);
	
	HidLaControllerSupportArg arg;
	
	hidLaCreateControllerSupportArg(&arg);
	
	arg.hdr.player_count_max = MAX_PLYR_COUNT;
	//arg.hdr.enable_single_mode = true;
	
	printf("welgum to worgaz epik APP!\n");
	printf("bress zr to reevaluate your controller choices.\n");
	printf("press b to quit like a CHICKEN....");
	
	// forgive me for coding like yandere dev
    while (appletMainLoop())
    {

		for (int i = 0; i<MAX_PLYR_COUNT; i++)
		{

			padUpdate(&pads[i]);
		
			if (padGetButtonsDown(&pads[i]) & HidNpadButton_ZR)
			{
				for (int j = 0; j<MAX_PLYR_COUNT; j++)
				{
					hidDisconnectNpad((HidNpadIdType)j);
				}
				hidLaShowControllerSupportForSystem(NULL, &arg, false);
			} 
			
			if (padGetButtonsDown(&pads[i]) & HidNpadButton_B)
			{
				consoleExit(0);
				exit(0);
			}
		
		}
		
		consoleUpdate(NULL);
		
    }
}
