import SideBar from './sideBar';
import CentralDash from './centralDash';

class Task
{
    goalName:string;
    color:any;
    taskName:string;
    taskDuration:number;
    taskStart:any;
    taskEnd:any;
    taskPriorty:string;
    subTaskList:any[];
    completed:boolean;
    constructor(gname:string,col:any,name:string,dur:number,st:any,en:any,pr:string,sublist:any[],comp:boolean)
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
    subTaskName:string;
    est:number;
    completed:boolean;
    constructor(name:string,est:number,comp:boolean)
    {
    this.subTaskName= name;
    this.est= est;
    this.completed= comp;
    }
}

class Goal
{
    goalName:string;
    goalDuration:number;
    goalStart:any;
    goalEnd:any;
    successCrit:string;
    completed:boolean;
    color:any;
    constructor(name:string,dur:number,st:any,end:any,succ:string,comp:boolean,col:any)
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

class User
{
    firstName:string;
    lastName:string;
    email:string;
    phoneNo:string;
    userName:string;
    dayStart:any;
    dayEnd:any;
    constructor(fn:string,ln:string,e:string,ph:string,us:string,dS:any,dE:any)
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



function DashBoard(prop:any)
{
    let TaskList = prop.TaskList;
    let GoalList = prop.GoalList;
    let UserCurr = prop.User;


    if(prop.TaskList == null || prop.GoalList == null)
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
        ocean: {border:"#a2ddca", main:"#308369"},
        pinkred:{border:"#9b4a65", main:"#d6a9b7"},
        darkgreen:{border:"#496a57", main:"#95b6a3"},
        brown:{border:"#928253", main:"#beb28d"},
        bblue:{border:"#3e5c74", main:"#8ba9c1"},
        brownred:{border:"#684b53", main:"#b497a0"}
    }
     TaskList = [
        new Task("My Goal",colorPalette.yellow, "My Task", 4, new Date("June 2, 2024 01:15:00"), new Date("June 30, 2024 01:15:00"),"Low", [new SubTask("Subtask 1",4,true),new SubTask("Subtask 2",5,false),new SubTask("Subtask 3",1,true)],false),

    ];

     GoalList = [
        new Goal("My Goal",10, new Date("2024-06-12"),new Date("2024-05-10"),"Hey man",false, colorPalette.grey),
        new Goal("Goal 2",100, new Date("2024-05-30"),new Date("2024-10-10"),"Are u sure",true, colorPalette.pinkred),

    ];
    }
    else
    {
        function correctDatesGoal(item:any,index:number)
        {
            GoalList[index].goalStart = new Date(item.goalStart);
            GoalList[index].goalEnd = new Date(item.goalEnd);
            GoalList[index].completed = (item.completed === "true") ? true : false;
        }

        function correctDatesTask(item:any,index:number)
        {
            TaskList[index].taskStart = new Date(item.taskStart);
            TaskList[index].taskEnd = new Date(item.taskEnd);
            TaskList[index].completed = (item.completed === "true") ? true : false;
            item.subTaskList.forEach((subtask:any,subIndex:number) => (subtask.completed === "true")? TaskList[index].subTaskList[subIndex].completed = true : TaskList[index].subTaskList[subIndex].completed = false )
        }
            GoalList.forEach((item:any,index:number)=> correctDatesGoal(item,index));
            TaskList.forEach((item:any,index:number)=> correctDatesTask(item,index));

    }

    if(prop.User == null)
    {
     UserCurr = new User("Default","User","example@gmail.com","0000000","username101",new Date("July 25, 2024 6:00:00"), new Date("July 25, 2024 18:00:00"));
    }
    else
    {
        function correctDatesUser()
        {
            UserCurr.dayStart = new Date(UserCurr.dayStart);
            UserCurr.dayEnd = new Date(UserCurr.dayEnd);
        }
        correctDatesUser();
    }





    return(
    <>
    <div className="d-flex flex-row bd-highlight mb-3">
        <div style={{padding:"1%"}}>
         <SideBar TaskList={TaskList} GoalList={GoalList}/>
        </div>
        <div style={{padding:"1%"}} className="flex-fill">
          <CentralDash TaskList={TaskList} User={UserCurr} GoalList={GoalList} apivalue={prop.apivalue}/>
        </div>
    </div>
    </>
    );
}

export default DashBoard;
