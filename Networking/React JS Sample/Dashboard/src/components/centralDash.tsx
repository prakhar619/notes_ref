import ProgressComp from "./progressBar";
import AddTask from "./addTask";
import AddGoal from "./addGoal";
import Modify from "./modify";
import ModifyGoal from "./modifyGoal";

import Button from 'react-bootstrap/Button';
import React from 'react'

function createProgressBar(task:any)
{
        let obj:any = {};
        obj.color = task.color;
        obj.internalContent = <h4> {task.taskName} </h4>;
        obj.progressborder = Math.round(100*Math.max(new Date().getTime() - task.taskStart.getTime(),0) / (task.taskEnd.getTime() - task.taskStart.getTime()));

        let remTime = 0;
        let completedTime = 0;
        task.subTaskList.forEach((item:any)=> item.completed ? completedTime+=item.est : remTime+=item.est);
        obj.progressmain = Math.round(100*completedTime/(remTime+completedTime));

        obj.heightborder = 4;
        obj.heightmain = 35;

        obj.taskEnd=task.taskEnd;
        obj.taskStart=task.taskStart;
        obj.completed = task.completed;

        return obj;
}

function filterGoal(List:any,activeGoal:string)
{
    let newList:any[] = [];
    List.forEach((item:any) => (item.goalName === activeGoal || activeGoal === "All Goals") && newList.push(item) );
    return newList;
}

function displaySubTask(subtask:any)
{
    return(
    <>
        <div style={{paddingRight:"20%",color:(subtask.completed == true)? "grey":"white"}}>
            <h6>{subtask.subTaskName}: {subtask.est} hrs</h6>
        </div>
    </>
    );
}

function displayTask(task:any,index:any,len:any,setModalTask:any,setModifyModal:any)
{
    if(task.completed == true)
        return;
    let progress = createProgressBar(task)
    return (
        <>
            <div className="d-flex flex-column bd-highlight mb-3">
                <div className="d-flex justify-content-between bd-highlight mb-3" style={{marginRight:"6%"}}>
                <div className="bd-highlight mb-3">
                    <h6 style={{color:task.color.main}} >{task.goalName}</h6>
                    <h3>{task.taskName}</h3>
                </div>
                <div>
                </div>
                <div>
                <Button style={{borderColor:task.color.main,color:task.color.main,backgroundColor:"transparent"}}  onClick={() => {setModalTask(task); setModifyModal(true);} }> Modify </Button>
                </div>
                </div>
                <div className="d-flex flex-row bd-highlight">
                    <small style={{color:"grey"}}>
                        Duration: {task.taskDuration} weeks  <br/>
                        Start: {task.taskStart.toDateString()} <br/>
                        End: {task.taskEnd.toDateString()} <br/>
                        Priorty: {task.taskPriorty}
                    </small>
                    <div className=" flex-fill" style={{paddingLeft:"20%"}}>
                        <h4>Subtasks</h4>
                        <div className="d-flex flex-row bd-highlight">
                            {task.subTaskList.map((item:any) => displaySubTask(item)) }
                        </div>
                    </div>
                </div>
                <div style={{maxWidth:"600px"}}>
                <ProgressComp item={progress}/>
                </div>
            </div>
    {len-1 !== index ? <hr /> : null}
        </>
    );
}
function CentralDash(prop:any)
{

    let GoalList = prop.GoalList;
    let User = prop.User;
    let TaskList = prop.TaskList;


    const [active,setactive] = React.useState("All Goals");
//     const [nowTime,setnowTime] = React.useState(new Date());
    let timeWidth =  Math.round(100*Math.max((new Date().getHours()*60+new Date().getMinutes())  -  (User.dayStart.getHours()*60+User.dayStart.getMinutes()),0) / ((User.dayEnd.getHours() - User.dayStart.getHours())*60 + (User.dayEnd.getMinutes() - User.dayStart.getMinutes())));

    const [TaskModal, setTaskModal] = React.useState(false);
    const [GoalModal, setGoalModal] = React.useState(false);
    const [GoalModifyModal, setGoalModifyModal] = React.useState(false);
    const [ModifyModal, setModifyModal] = React.useState(false);
    const [ModalTask, setModalTask] = React.useState(TaskList[0]);


    let TodayTaskList:any[] = [];
    let QueueList:any[] = [];
    TaskList.forEach( (item:any) => (item.taskEnd.getDate() == new Date().getDate() && item.taskEnd.getMonth() == new Date().getMonth() && item.taskEnd.getFullYear() == new Date().getFullYear()) ? TodayTaskList.push(item): QueueList.push(item) );
    QueueList = filterGoal(QueueList,active);

    return(
    <>
    <Modify apivalue={prop.apivalue}  GoalList={GoalList}  task={ModalTask} show={ModifyModal} onHide={() => setModifyModal(false)}/>
        <div className="topSticky d-flex flex-row bd-highlight mb-3">
                <div className=" d-flex  flex-column bd-highlight mb-7" style={{marginRight:"1%"}}>
                    <h2>Hello, {User.firstName}</h2>
                    <div className="d-flex flex-row bd-highlight mb-3">
                    <div style={{padding:"1%"}}>
                    <AddGoal apivalue={prop.apivalue} show={GoalModal} onHide={() => setGoalModal(false)}/>
                    <Button variant="primary" onClick={() => setGoalModal(true)}>  Add Goal  </Button>
                    </div>
                    <div style={{padding:"1%"}}>
                    <AddTask apivalue={prop.apivalue} goalList={GoalList} show={TaskModal} onHide={() => setTaskModal(false)}/>
                    <Button variant="primary" onClick={() => setTaskModal(true)}>  Add Task  </Button>
                    </div>

                    </div>

                </div>

                <div className="flex-fill">
                    <ul className="nav nav-tabs nav-fill">
                        {(active === "All Goals") ?  <li className="nav-item"><a className="nav-link active" href="#">All Goals</a> </li>: <li className="nav-item"><a className="nav-link" onClick={()=>setactive("All Goals")} href="#">All Goals</a> </li> }
                        {GoalList.map( (goal:any)=>(goal.completed == false) ? ((goal.goalName === active) ? <li className={"nav-item"}> <a className="nav-link active" style={{backgroundColor:goal.color.main}} aria-current="page" href="#">{goal.goalName}</a> </li> : <li className="nav-item"><a className="nav-link" onClick={()=>setactive(goal.goalName)} href="#">{goal.goalName}</a> </li>): null)}
                    </ul>
                    <div className="d-flex">
                    <div className="p-2 flex-grow-1 "><input className="form-control me-2 " type="search" placeholder="Search" aria-label="Search" /></div>
                    <div className="p-2"> <button className="btn btn-outline-success" type="submit">Search</button></div>
                    <ModifyGoal apivalue={prop.apivalue} GoalList={GoalList} show={GoalModifyModal} onHide={() => setGoalModifyModal(false)}/>
                    <div className="p-2"> <button className="btn btn-outline-danger" onClick={() => setGoalModifyModal(true)}>Modify Goal</button></div>
                    </div>
                </div>
        </div>
    <div className="container-fluid d-flex flex-column bd-highlight mb-3" style={{paddingTop:"40px",paddingLeft:"3%",backgroundColor:"#1B1B1B", borderRadius:"24px",minHeight:"830px"}}>


        <div className="bottom" style={{paddingTop:""}}>
                <div className="progress" style={{height: "1px"}}>
                <div className="progress-bar bg-secondary" role="progressbar" style={{width:timeWidth.toString()+"%"}} ></div>
                </div>

                <div className="dailyTask d-flex flex-row bd-highlight mb-3" style={{paddingTop:"25px",}} >
                    <div style={{paddingRight:"1.5%"}}><h2> Today's </h2><h2> Target </h2></div>
                    <div className=" flex-fill flex-column bd-highlight" style={{paddingLeft:"20px",}}>
                        {TodayTaskList.map( (item:any,index:number)=> displayTask(item,index,TodayTaskList.length,setModalTask,setModifyModal))}
                    </div>
                </div>
                <hr/>
                <div className="queue d-flex flex-row bd-highlight mb-3 " style={{paddingTop:"25px",}}>
                <div style={{paddingRight:"1.5%"}}><h2> Queue </h2></div>
                <div className=" flex-fill flex-column bd-highlight overflow-auto" style={{paddingLeft:"20px",maxHeight:"800px"}}>
                {QueueList.map( (item:any,index:number)=> displayTask(item,index,QueueList.length,setModalTask,setModifyModal))}
                </div>
                </div>
        </div>

    </div>
</>
    );

}

export default CentralDash;
