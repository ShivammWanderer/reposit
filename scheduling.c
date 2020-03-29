#include<stdio.h>

struct job{
	int process_id, arrival_time, burst_time, turnaround_time, rem_burst_time;
}faculty_q[50], students_q[50], merge_q[50];

int n, faculty_ptr=0, students_ptr=0, merge_ptr=0;
int quanta;

void scheduling(){
	int stamp= merge_q[0].arrival_time, limit=0, rem_counter, counter=0;
	while(stamp!=120 && counter!=merge_ptr){
		for(int i=0; i<=limit; i++){
			if(merge_q[i].rem_burst_time > quanta){
				stamp += quanta;
				merge_q[i].rem_burst_time -= quanta;
			}
			else if(merge_q[i].rem_burst_time <=quanta && merge_q[i].rem_burst_time!=0){
				stamp += merge_q[i].rem_burst_time;
				merge_q[i].rem_burst_time =0;
				merge_q[i].turnaround_time = stamp;
				counter++;
			}
			else;
		}
		int start = limit+1;
		for(rem_counter= start; rem_counter<merge_ptr; rem_counter++){
			if(merge_q[rem_counter].arrival_time <= stamp){
				limit++;
			}
		}
	}
}

void merger(){
	int students_counter=0, faculty_counter= 0, min, flag;
	if( faculty_ptr!=0  && students_ptr!=0){
		while(students_counter<students_ptr && faculty_counter<faculty_ptr){
			if(faculty_q[faculty_counter].arrival_time == students_q[students_counter].arrival_time){
				merge_q[merge_ptr] = faculty_q[faculty_counter];
				merge_ptr++;
				faculty_counter++;
				merge_q[merge_ptr]= students_q[students_counter];
				merge_ptr++;
				students_counter++;
			}
			else if(faculty_q[faculty_counter].arrival_time < students_q[students_counter].arrival_time){
				merge_q[merge_ptr]= faculty_q[faculty_counter];
				merge_ptr++;
				faculty_counter++;
			}
			else if(faculty_q[faculty_counter].arrival_time > students_q[students_counter].arrival_time){
				merge_q[merge_ptr]= students_q[students_counter];
				merge_ptr++;
				students_counter++;
			}
			else;
		}
		if(merge_ptr != (faculty_ptr+students_ptr)){
			if(faculty_ptr!=faculty_counter){
				while(faculty_counter!=faculty_ptr){
					merge_q[merge_ptr]= faculty_q[faculty_counter];
					merge_ptr++;
					faculty_counter++;
				}
			}
			else if(students_ptr!=students_counter){
				while(students_counter!=students_ptr){
					merge_q[merge_ptr]= students_q[students_counter];
					merge_ptr++;
					students_counter++;
				}
			}
		}
	}
	else if(faculty_ptr==0){
		while(students_counter!=students_ptr){
			merge_q[merge_ptr]= students_q[students_counter];
			merge_ptr++;
			students_counter++;
		}
	}
	else if(students_ptr==0){
		while(faculty_counter!=faculty_ptr){
			merge_q[merge_ptr]= faculty_q[faculty_counter];
			merge_ptr++;
			faculty_counter++;
		}
	}
	else {
		printf("\n There are no valid queries to be served\n");
	}
}

void display(){
	int total_time=0, sum=0;
	double average_time;
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(int i; i<merge_ptr; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		merge_q[i].process_id, (merge_q[i].arrival_time+1000), merge_q[i].burst_time, (merge_q[i].turnaround_time+1000),
         (merge_q[i].turnaround_time-merge_q[i].arrival_time),
         ((merge_q[i].turnaround_time-merge_q[i].arrival_time)- merge_q[i].burst_time));
		total_time= merge_q[i].turnaround_time;
		sum+= (merge_q[i].turnaround_time-merge_q[i].arrival_time);
	}
	average_time = sum/merge_ptr;
	printf("\n\nTotal time Spent for all queries: %d", total_time);
	printf("\nAverage query time: %lf", average_time);
}

void query_entry(){
	int type_of_query, time_of_arrival, no_of_queries;
	printf("Enter total no of queries: ");
	scanf("%d", &no_of_queries);
	if(no_of_queries==0)
        {
             printf("\n Please, enter valid number of queries\n");
        }
	else
	{
		printf("\nEnter the value of Quanta: ");
        scanf("%d", &quanta);
        printf("\nChoose the type of Query from the options below\n");
        printf("1 for Faculty Query\n");
		printf("2 for Student Query\n");
		for(int i=0; i<no_of_queries; i++){
            printf("\nQuery Type Please (1/2): "); scanf("%d", &map);
            scanf("%d", &type_of_query);
			 if(type_of_query==1){
                printf("Query Id: ");
				printf("Enter The Required Value For The Query\n");
				scanf("%d", &faculty_q[faculty_ptr].process_id);
				printf("Arrival Time: ");
                scanf("%d", &time_of_arrival);
				if(time_of_arrival<1000 || time_of_arrival>1200){
                   printf("Login Time is 10AM to 12AM only:\n Sorry for the Inconvenience\n");
                   query_entry();
                }
            else{
                faculty_q[faculty_ptr].arrival_time= time_of_arrival-1000;
                }
				printf("Burst Time: ");
				 scanf("%d", &faculty_q[faculty_ptr].burst_time);
				  faculty_q[faculty_ptr].rem_burst_time= faculty_q[faculty_ptr].burst_time;
				faculty_ptr++;
			}
			else{
				printf("Query Id: ");
				scanf("%d", &students_q[students_ptr].process_id);
				printf("Arrival Time: ");
                scanf("%d", &time_of_arrival);
				if(time_of_arrival<1000 || time_of_arrival>1200){
                     printf("\nPlease Abide By The Time Constraints(10AM to 12AM only)\n");
                     query_entry();
                }
				else {students_q[students_ptr].arrival_time= time_of_arrival-1000; }
				printf("Burst Time: ");
                scanf("%d", &students_q[students_ptr].burst_time);
                students_q[students_ptr].rem_burst_time= students_q[students_ptr].burst_time;
				students_ptr++;
			}
		}
	}
}



 void main(){
    printf("Time is implemented in Military Time Format(2400 Hours Time), where 10AM is equivalent to 1000,\n",
            "12PM is equivalent to 1200 and accordingly. \n", "For instance to represent 11:33 AM enter 1133\n ");
    query_entry();
	merger();
	scheduling();
	display();
}
