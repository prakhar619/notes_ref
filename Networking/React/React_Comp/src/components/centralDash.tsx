import SearchBar from './searchBar';
import ProgressComp from "./progressBar";
import GoalSvg from "./../assets/goals.svg"
import LoginUser from "./loginUser";
import RegisterUser from "./registerUser";
import AddTask from "./addTask";
import AddGoal from "./addGoal";

import Button from 'react-bootstrap/Button';
import Modal from 'react-bootstrap/Modal';
import React from 'react'


function createProgressBar(task)
{
        let obj = {color:null, internalContent:null,progressborder:null,progressmain:null,heightborder:null,heightmain:null,taskEnd:null,taskEnd:null,completed:null};
        obj.color = task.color;
        obj.internalContent = <h4> {task.taskName} </h4>;
        obj.progressborder = Math.round(100*Math.max(new Date().getTime() - task.taskStart.getTime(),0) / (task.taskEnd.getTime() - task.taskStart.getTime()));

        let remTime = 0;
        let completedTime = 0;
        task.subTaskList.forEach((item)=> item.completed ? completedTime+=item.est : remTime+=item.est);
        obj.progressmain = Math.round(100*completedTime/(remTime+completedTime));

        obj.heightborder = 4;
        obj.heightmain = 35;

        obj.taskEnd=task.taskEnd;
        obj.taskStart=task.taskStart;
        obj.completed = task.completed;

        return obj;
}

function filterGoal(List,activeGoal)
{
    let newList = [];
    List.forEach(item => (item.goalName === activeGoal || activeGoal === "All Goals") ? newList.push(item): null);
    return newList;
}

function displaySubTask(subtask)
{
    return(
    <>
        <div style={{paddingRight:"20%"}}>
            <h6>{subtask.subTaskName}: {subtask.est}</h6>
        </div>
    </>
    );
}

function displayTask(task,index,len)
{
    let progress = createProgressBar(task)
    return (
        <>
            <div class="d-flex flex-column bd-highlight mb-3">
                <div class="d-flex flex-column bd-highlight mb-3">
                    <h6 class="">{task.goalName}</h6>
                    <h3>{task.taskName}</h3>
                </div>
                <div class="d-flex flex-row bd-highlight">
                    <p class="">
                        Duration: {task.taskDuration} <br/>
                        Start:{task.taskStart.getDate()} End:{task.taskEnd.getDate()} <br/>
                        Priorty:{task.taskPriorty}
                    </p>
                    <div class=" flex-fill" style={{paddingLeft:"20%"}}>
                        <h4>Subtasks</h4>
                        <div class="d-flex flex-row bd-highlight">
                            {task.subTaskList.map(item => displaySubTask(item)) }
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
function CentralDash(prop)
{

    let GoalList = prop.GoalList;
    let User = prop.User;
    let TaskList = prop.TaskList;


    const [active,setactive] = React.useState("All Goals");
//     const [nowTime,setnowTime] = React.useState(new Date());
    let timeWidth =  Math.round(100*Math.max((new Date().getHours()*60+new Date().getMinutes())  -  (User.dayStart.getHours()*60+User.dayStart.getMinutes()),0) / ((User.dayEnd.getHours() - User.dayStart.getHours())*60 + (User.dayEnd.getMinutes() - User.dayStart.getMinutes())));

    const [TaskModal, setTaskModal] = React.useState(false);
    const [GoalModal, setGoalModal] = React.useState(false);

    let TodayTaskList = [];
    let QueueList = [];
    TaskList.forEach( item => (item.taskEnd.getDate() == new Date().getDate() && item.taskEnd.getMonth() == new Date().getMonth() && item.taskEnd.getYear() == new Date().getYear() && item.completed !== true) ? TodayTaskList.push(item): QueueList.push(item) );
    QueueList = filterGoal(QueueList,active);

    return(
    <>
    <div class="container-fluid d-flex flex-column bd-highlight mb-3" style={{paddingTop:"40px",paddingLeft:"3%",backgroundColor:"#1B1B1B", borderRadius:"24px",minHeight:"830px"}}>

        <div class="topSticky d-flex flex-row bd-highlight mb-3">
                <div class=" d-flex  flex-column bd-highlight mb-3" style={{paddingRight:"1.5%"}}>
                    <h2>Hello, {User.firstName}</h2>
                    <div class="d-flex flex-row bd-highlight mb-3">
                    <div style={{padding:"1%"}}>
                    <AddGoal show={GoalModal} onHide={() => setGoalModal(false)}/>
                    <Button variant="primary" onClick={() => setGoalModal(true)}>  Add Goal  </Button>
                    </div>
                    <div style={{padding:"1%"}}>
                    <AddTask  goalList={GoalList} show={TaskModal} onHide={() => setTaskModal(false)}/>
                    <Button variant="primary" onClick={() => setTaskModal(true)}>  Add Task  </Button>
                    </div>
                    </div>
                </div>

                <div class="flex-fill">
                    <ul class="nav nav-tabs nav-fill">
                        {(active === "All Goals") ?  <li class="nav-item"><a class="nav-link active" href="#">All Goals</a> </li>: <li class="nav-item"><a class="nav-link" onClick={()=>setactive("All Goals")} href="#">All Goals</a> </li> }
                        {GoalList.map( (goal,index)=>(goal.goalName === active) ? <li class={"nav-item"}> <a class="nav-link active" style={{backgroundColor:goal.color.main}} aria-current="page" href="#">{goal.goalName}</a> </li> : <li class="nav-item"><a class="nav-link" onClick={()=>setactive(goal.goalName)} href="#">{goal.goalName}</a> </li>)}
                    </ul>
                    <div class="d-flex ">
                    <div class="p-2 flex-grow-1 "><input class="form-control me-2 " type="search" placeholder="Search" aria-label="Search" /></div>
                    <div class="p-2"> <button class="btn btn-outline-success" type="submit">Search</button></div>
                    </div>
                </div>
        </div>

        <div class="bottom" style={{paddingTop:""}}>
                <div class="progress" style={{height: "1px"}}>
                <div class="progress-bar bg-secondary" role="progressbar" style={{width:timeWidth.toString()+"%"}}  aria-valuemin="0" aria-valuemax="100"></div>
                </div>

                <div class="dailyTask d-flex flex-row bd-highlight mb-3" style={{paddingTop:"25px",}} >
                    <div style={{paddingRight:"1.5%"}}><h2> Today's </h2><h2> Target </h2></div>
                    <div class=" flex-fill flex-column bd-highlight" style={{paddingLeft:"20px",}}>
                        {TodayTaskList.map( (item,index)=> displayTask(item,index,TodayTaskList.length))}
                    </div>
                </div>
                <hr/>
                <div class="queue d-flex flex-row bd-highlight mb-3 " style={{paddingTop:"25px",}}>
                <div style={{paddingRight:"1.5%"}}><h2> Queue </h2></div>
                <div class=" flex-fill flex-column bd-highlight overflow-auto" style={{paddingLeft:"20px",maxHeight:"800px"}}>
                {QueueList.map( (item,index)=> displayTask(item,index,QueueList.length))}
                </div>
                </div>
        </div>

    </div>
</>
    );

}

export default CentralDash;
