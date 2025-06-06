#include <public/ccobsmng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCObsMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCObsMng &act ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	ObsCtrl(EDROOMcomponent.ObsCtrl),
	ObservTimer(EDROOMcomponent.ObservTimer),
	AttitudeCtrl_Timer(EDROOMcomponent.AttitudeCtrl_Timer),
	CImageInterval(0,5)
{
}

CCObsMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	ObsCtrl(context.ObsCtrl),
	ObservTimer(context.ObservTimer),
	AttitudeCtrl_Timer(context.AttitudeCtrl_Timer),
	CImageInterval(0,5)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCObsMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCObsMng::EDROOM_CTX_Top_0::FDoActtitudeCtrl()

{

pus_service129_do_attitude_ctrl();

}



void	CCObsMng::EDROOM_CTX_Top_0::FEndObservation())

{

VNextTimeOut.GetTime();
pus_service129_end_observation();

}



void	CCObsMng::EDROOM_CTX_Top_0::FInit_Obs()

{
   //Define absolute time
  Pr_Time time;
	 
	//Timing Service useful methods
	 
	time.GetTime(); // Get current monotonic time
	time.Add(0,100000); // Add X sec + Y microsec
        VNextTimeout=time;
 
   //Program absolute timer 
   AttitudeCtrl_Timer.InformAt( time ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FObsCtrl_Exec()

{
   //Handle Msg->data
  CDTCHandler & varSObsMng_TC = *(CDTCHandler *)Msg->data;
	
varSObsMng_TC.ExecTC();
 

}



void	CCObsMng::EDROOM_CTX_Top_0::FProgAttitudeCtrl()()

{
   //Define absolute time
  Pr_Time time;
	 
	
	 
	
VNextTimeout+= Pr_Time(0,100000); // Add X sec + Y microsec 
time=VNextTimeout; 
   //Program absolute timer 
   AttitudeCtrl_Timer.InformAt( time ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FProgTakeImage()

{
   //Define interval
  Pr_Time interval;
	
	//Timing Service useful methods
	 
	interval = CImageInterval; // interval of X sec + Y microsec
	 
	
   //Program relative timer 
   ObservTimer.InformIn( interval ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FTakeImage()

{

pus_service129_take_image();

}



void	CCObsMng::EDROOM_CTX_Top_0::FToObservation()

{

pus_service129_start_observation();

}



bool	CCObsMng::EDROOM_CTX_Top_0::GLastImage()()

{

return_pus_service129_is_last_image()

}



bool	CCObsMng::EDROOM_CTX_Top_0::GReadyToObservation()

{

return_pus_service129_is_observation_ready();

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCObsMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCObsMng&act):
		EDROOM_CTX_Top_0(act)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCObsMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Execute Action 
				FInit_Obs();
				//Next State is Standby
				edroomNextState = Standby;
				break;
			//To Choice Point Guard1
			case (Guard1):

				//Execute Action 
				FDoActtitudeCtrl();
				//Evaluate Branch False
				if( GReadyToObservation() )
				{

					//Branch taken is Guard1_False
					edroomCurrentTrans.localId =
						Guard1_False;

					//Next State is Standby
					edroomNextState = Standby;
				 } 
				//Default Branch True
				else
				{

					//Branch taken is Guard1_True
					edroomCurrentTrans.localId =
						Guard1_True;

					//Next State is Observation
					edroomNextState = Observation;
				 } 
				break;
			//To Choice Point Guard2
			case (Guard2):

				//Execute Action 
				FTakeImage();
				//Evaluate Branch True1
				if( GLastImage()() )
				{
					//Execute Actions 
					FEndObservation();
					FProgAttitudeCtrl();

					//Branch taken is Guard2_True1
					edroomCurrentTrans.localId =
						Guard2_True1;

					//Next State is Standby
					edroomNextState = Standby;
				 } 
				//Default Branch False1
				else
				{

					//Branch taken is Guard2_False1
					edroomCurrentTrans.localId =
						Guard2_False1;

					//Next State is Observation
					edroomNextState = Observation;
				 } 
				break;
			//Next Transition is TcExec
			case (TcExec):
				//Msg->Data Handling 
				FObsCtrl_Exec();
				//Next State is Standby
				edroomNextState = Standby;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state Standby
			case (Standby):
				//Arrival to state Standby
				edroomCurrentTrans=EDROOMStandbyArrival();
				break;

				//Go to the state Observation
			case (Observation):
				//Execute Entry Action 
				FProgTakeImage();
				//Arrival to state Observation
				edroomCurrentTrans=EDROOMObservationArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCObsMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Standby

	// ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMStandbyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == AttitudeCtrl_Timer)
				{

					//Next transition is  Guard1
					edroomCurrentTrans.localId = Guard1;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

			case (SObsMng_TC): 

				 if (*Msg->GetPInterface() == ObsCtrl)
				{

					//Next transition is  TcExec
					edroomCurrentTrans.localId= TcExec;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Observation

	// ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMObservationArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == ObservTimer)
				{

					//Next transition is  Guard2
					edroomCurrentTrans.localId = Guard2;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



