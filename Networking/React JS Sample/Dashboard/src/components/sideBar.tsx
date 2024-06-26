import SidebarMenu from 'react-bootstrap-sidebar-menu';
import Calender from './calendar.tsx';
import ProgressBar from './progressBar';

function createProgressBarTask(task:any)
{
    let obj:any = {color:"", internalContent:"",progressborder:1,progressmain:1,heightborder:1,heightmain:1,taskStart:1,taskEnd:1,completed:1};
    obj.color = task.color;
    obj.internalContent = <h5> {task.taskName} </h5>;
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

function createProgressBarGoal(goal:any,TaskList:any[])
{
    let obj:any = {color:"", internalContent:"",progressborder:1,progressmain:1,heightborder:1,heightmain:1,taskStart:1,taskEnd:1,completed:1};
    obj.color = goal.color;
    obj.internalContent = <h5> {goal.goalName} </h5>;
    obj.progressborder = Math.round(100*Math.max(new Date().getTime() - goal.goalStart.getTime(),0) / (goal.goalEnd.getTime() - goal.goalStart.getTime()));

    let remTime = 0;
    let completedTime = 0;
    for(let i = 0; i < TaskList.length; i++)
    {
        if(TaskList[i].goalName === goal.goalName)
            TaskList[i].subTaskList.forEach((item:any)=> item.completed ? completedTime+=item.est : remTime+=item.est);
        else
        completedTime = 1;
    }
    obj.progressmain =  Math.round(100*completedTime/(remTime+completedTime))
    obj.heightborder = 4;
    obj.heightmain = 35;

    obj.taskEnd=goal.goalEnd;
    obj.taskStart=goal.goalStart;
    obj.completed = goal.completed;

    return obj;
}

function SideBar(prop:any)
{
    let TaskList:any[] = prop.TaskList;
    let GoalList:any[] = prop.GoalList;

    let ProgressBarTask:any[] = [];
    TaskList.forEach((task:any)=> (task.completed == false) ? ProgressBarTask.push(createProgressBarTask(task)): null);

    let ProgressBarGoal:any[] = [];
    GoalList.forEach((task:any)=> (task.completed == false) ? ProgressBarGoal.push(createProgressBarGoal(task,TaskList)): null);

    return(
        <div>
        <SidebarMenu>
                    <SidebarMenu.Header >
                    <SidebarMenu.Brand>
                <div >  <Calender /> </div>
                    </SidebarMenu.Brand>
                    </SidebarMenu.Header>

        <SidebarMenu.Body className="overflow-auto" style={{height:"900px"}}>
            <div style={{padding:"1%"}}>
                <SidebarMenu.Sub>
                <SidebarMenu.Sub.Toggle bsPrefix="p-1 btn btn-outline-secondary rounded-3">
                <h5 style={{paddingTop:"9px"}}>Goals</h5>
                </SidebarMenu.Sub.Toggle>
                            <SidebarMenu.Sub.Collapse>
                                <SidebarMenu.Nav>
                                    {ProgressBarGoal.map((item:any) =><div style={{padding:"1%"}}><SidebarMenu.Nav.Item><ProgressBar item={item}/></SidebarMenu.Nav.Item></div>)}
                                </SidebarMenu.Nav>
                            </SidebarMenu.Sub.Collapse>
                </SidebarMenu.Sub>
            </div>

            <div style={{padding:"1%"}}>
                <SidebarMenu.Sub>
                <SidebarMenu.Sub.Toggle bsPrefix="p-1 btn btn-outline-secondary rounded-3">
                <h5 style={{paddingTop:"9px"}}>Tasks</h5>
                </SidebarMenu.Sub.Toggle>
                            <SidebarMenu.Sub.Collapse>
                                <SidebarMenu.Nav>
                                    {ProgressBarTask.map((item:any) =><div style={{padding:"1%"}}><SidebarMenu.Nav.Item><ProgressBar item={item}/></SidebarMenu.Nav.Item></div>)}
                                </SidebarMenu.Nav>
                            </SidebarMenu.Sub.Collapse>
                </SidebarMenu.Sub>
            </div>
        </SidebarMenu.Body>

        <SidebarMenu.Footer>
        </SidebarMenu.Footer>

        </SidebarMenu>
    </div>
    );
}

export default SideBar;
