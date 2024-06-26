import SideBar from './sideBar';
import CentralDash from './centralDash';

class Task
{
    constructor(gname,col,name,dur,st,en,pr,sublist,comp)
    {
    this.goalName= gname;
    this.color= col;
    this.taskName= name;
    this.taskDuration= dur;
    this.taskStart= st;
    this.taskEnd= en;
    this.taskPriorty= pr;
    this.subTaskList= sublist;
    this.completed= comp;
    }
}

class SubTask
{
    constructor(name,est,comp)
    {
    this.subTaskName= name;
    this.est= est;
    this.completed= comp;
    }
}

class Goal
{
    constructor(name,dur,st,end,succ,comp,col)
    {
    this.goalName=name;
    this.goalDuration= dur;
    this.goalStart=st;
    this.goalEnd= end;
    this.successCrit=succ;
    this.completed= comp;
    this.color=col;
    }
}

class Color
{
    constructor(colorB,colorM)
    {
        this.border = colorB;
        this.main = colorM;
    }
}


class User
{

    constructor(fn,ln,e,ph,us,dS,dE)
    {
    this.firstName=fn;
    this.lastName= ln;
    this.email=e;
    this.phoneNo=ph;
    this.userName=us;
    this.dayStart=dS;
    this.dayEnd=dE;
    }
}



function DashBoard()
{
    let colorPalette = {
        blue : { border:" #2e86c1",main:"#85c1e9"},
        red  : { border:"#cb4335",main:"#f1948a"},
        purple: { border:" #7d3c98 ",main:" #bb8fce"},
        green: { border:" #229954 ",main:"#7dcea0"},
        yellow: { border:" #d4ac0d ",main:" #f7dc6f"},
        orange: { border:" #d68910 ",main:"#f8c471"},
        grey: { border:" #839192 ",main:"#bfc9ca"},
        steal: { border:" #17a589 ",main:" #76d7c4 "},
    }
    let TaskList = [
        new Task("Goal 1",colorPalette.yellow, "Task 1", 4, new Date("June 2, 2024 01:15:00"), new Date("June 30, 2024 01:15:00"),1, [new SubTask("subTask1",4,true),new SubTask("subTask2",5,false),new SubTask("subTask3",1,true)],false),
        new Task("Goal 1",colorPalette.yellow, "Task 2", 4, new Date("June 20, 2024 01:15:00"), new Date("June 30, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),
        new Task("Goal 1",colorPalette.yellow, "Task 3", 4, new Date("June 1, 2024 01:15:00"), new Date("June 15, 2024 01:15:00"),1, [new SubTask("subTask1",4,true),new SubTask("subTask1",4,false)],false),
        new Task("Goal 2",colorPalette.red, "Task 1", 4, new Date("May 12, 2024 01:15:00"), new Date("July 1, 2024 01:15:00"),1, [new SubTask("subTask1",4,true),new SubTask("subTask2",8,false),new SubTask("subTask3",4,false)],false),
        new Task("Goal 3",colorPalette.purple, "Task 1", 4, new Date("June 1, 2024 01:15:00"), new Date("June 25, 2024 01:15:00"),1, [new SubTask("subTask1",4,false),new SubTask("subTask2",4,false)],false),
        new Task("Goal 4",colorPalette.orange, "Task 1", 4, new Date("May 1, 2023 01:15:00"), new Date("June 16, 2024 01:15:00"),1, [new SubTask("subTask1",4,true),new SubTask("subTask1",4,true)],false),
        new Task("Goal 5",colorPalette.green, "Task 1", 4, new Date("May 1, 2024 01:15:00"), new Date("June 16, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),
        new Task("Goal 6",colorPalette.blue, "Task 1", 4, new Date("May 1, 2024 01:15:00"), new Date("July 25, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),
        new Task("Goal 3",colorPalette.purple, "Task 2", 4, new Date("May 1, 2024 01:15:00"), new Date("July 25, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),
        new Task("Goal 5",colorPalette.green, "Task 2", 4, new Date("May 1, 2024 01:15:00"), new Date("July 25, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),
        new Task("Miscell",colorPalette.grey, "Task 4", 4, new Date("May 1, 2024 01:15:00"), new Date("July 25, 2024 01:15:00"),1, [new SubTask("subTask1",4,true)],false),



    ];

    let GoalList = [
        new Goal("Miscell",10, new Date("May 1, 2024 01:15:00"),new Date("July 1, 2024 01:15:00"),"Hey man",false, colorPalette.grey),
        new Goal("Goal 1",10, new Date("May 1, 2024 01:15:00"),new Date("July 1, 2024 01:15:00"),"Hey man",false, colorPalette.yellow),
        new Goal("Goal 2",8, new Date("May 12, 2024 01:15:00"),new Date("June 1, 2024 01:15:00"),"Hey man",false, colorPalette.red),
        new Goal("Goal 3",3, new Date("June 12, 2024 01:15:00"),new Date("June 25, 2024 01:15:00"),"Hey man",false, colorPalette.purple),
        new Goal("Goal 4",11, new Date("May 1, 2024 01:15:00"),new Date("June 16, 2024 01:15:00"),"Hey man",false, colorPalette.orange),
        new Goal("Goal 5",10, new Date("May 1, 2024 01:15:00"),new Date("July 1, 2024 01:15:00"),"Hey man",false, colorPalette.green),
        new Goal("Goal 6",10, new Date("May 1, 2024 01:15:00"),new Date("July 1, 2024 01:15:00"),"Hey man",false, colorPalette.blue)
    ];

    let UserCurr = new User("Prakhar","Gupta","prakhar619lm10@gmail.com","8858968971","revai@ackreman",new Date("July 25, 2024 6:00:00"), new Date("July 25, 2024 18:00:00"));



    return(
    <>
    <div class="d-flex flex-row bd-highlight mb-3">
        <div style={{padding:"1%"}}>
         <SideBar TaskList={TaskList} GoalList={GoalList}/>
        </div>
        <div style={{padding:"1%"}} class="flex-fill">
          <CentralDash TaskList={TaskList} User={UserCurr} GoalList={GoalList}/>
        </div>
    </div>
    </>
    );
}

export default DashBoard;
