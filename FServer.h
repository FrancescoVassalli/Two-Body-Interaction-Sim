/*
   Setup the runs and maintain a list of the topnode for each run. 
   Begin each run and pass the topnode for the run to each subsystem at the start of every event.
   At the end of each event read the output of all the subsystems and determine what to do.
   After each run is terminated end the program.
 */

#ifndef FSERVER_H
#define FSERVER_H

#include <vector>

class FNode;
class FSubsystem;

class FServer 
{
	public:
		static FServer *instance();
		virtual ~FServer();


		int registerSubsystem(FSubsystem *subsystem, const std::string &topnodename = "TOP");
		int unregisterSubsystem(FSubsystem *subsystem);
		FSubsystem *getFSubsystem(const std::string &name);
		virtual void Print(const std::string &what = "ALL") const;

		void InitAll();
		int process_event(FNode *topNode);
		int Reset();
		virtual int BeginRun(const int runno);
		virtual int EndRun(const int runno = 0);
		virtual int End();
		FNode *topNode() const { return TopNode; }
		FNode *topNode(const std::string &name);
		virtual int process_event();
		/* not sure about these methods*/
		FNode *getNode(const std::string &name, const std::string &topnodename = "TOP");
		int AddTopNode(const std::string &name);
		int MakeNodesTransient(FNode *startNode);
		int MakeNodesPersistent(FNode *startNode);

		//! run n events (0 means up to end of file)
		int run(const int nevnts = 0, const bool require_nevents = false);

		/*! 
		  \brief skip n events (0 means up to the end of file). 
		  Skip means read, don't process.
		 */
		int skip(const int nevnts = 0);

		int SegmentNumber();
		int ResetNodeTree();
		virtual void identify(std::ostream &out = std::cout) const;
		void EventNumber(const int evtno) { eventnumber = evtno; }
		void NodeIdentify(const std::string &name);

	protected:
		FServer(const std::string &name = "FServer");
		int InitNodeTree(FNode *topNode);
		int unregisterSubsystemsNow();
		int setRun(const int runnumber);
		static FServer *__instance;
		std::vector<FNode*> topNodes;

		int runnumber;
		int eventnumber;

		std::map<std::string, FNode *> topnodemap;
};

#endif
