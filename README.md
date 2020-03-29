# reposit
New Repository
Problem:
Sudesh sharma is a linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log onto the system from 10AM to 12AM only. He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.






Description:

The given problem requires a system to handle student queries in a specific way. These queries are analogous to the processes in Operating System
There can be multiple requests at any time, these requests have their own resource need so we need to order them based on particular criteria. This is the concept of Scheduling in Operating System  in which processes are allocated and de-allocated the CPU based on particular Strategy which  is the responsibility of the Process Manager.
Here, Mr. Sudesh wishes to dedicate a fixed amount of time to every incoming request so accordingly we would perform Robin Robin Scheduling which has the concept of “Quantum”. Quantum is the fixed amount of time for which CPU is allocated  to any process and after which other process from the queue is allotted the resources. This continues until all the processes are served.
Now, Mr Sudesh wants to separate requests queues for Faculty and Students,  with Faculty queue having higher priority, this is also the concept of Operating System in which various queues are made based on the priority of the processes.
Mr. Sudesh can be basically seen as CPU of Operating System. 
