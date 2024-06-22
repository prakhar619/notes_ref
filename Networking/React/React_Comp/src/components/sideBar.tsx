import SidebarMenu from 'react-bootstrap-sidebar-menu';
import Calender from './calendar.tsx';
import ProgressBar from './progressBar';


function SideBar(prop)
{
    let TaskList = prop.TaskList;
    let GoalList = prop.GoalList;

    let ProgressBarList = [];
    function createProgressBarList(task)
    {
        let obj = {color:null, internalContent:null,progressborder:null,progressmain:null,heightborder:null,heightmain:null,taskEnd:null,taskEnd:null,completed:null};
        obj.color = task.color;
        obj.internalContent = <h4> {task.taskName} </h4>;
        obj.progressborder = Math.round(100*Math.max( new Date().getTime() - task.taskStart.getTime(),0 ) / (task.taskEnd.getTime() - task.taskStart.getTime()));

        let remTime = 0;
        let completedTime = 0;
        task.subTaskList.forEach((item)=> item.completed ? completedTime+=item.est : remTime+=item.est);
        obj.progressmain = Math.round(100*completedTime/(remTime+completedTime));

        obj.heightborder = 3;
        obj.heightmain = 25;

        ProgressBarList.push(obj);
    }
    TaskList.forEach(createProgressBarList);

    let GoalProgressBar = []
    let remain = 0;
    let complete = 0;
    function TaskComp(task)
    {
        task.subTaskList.forEach(subTask => subTask.completed ? complete += subTask.est :remain += subTask.est);
        return [complete,remain];
    }
    function goalComp(goalName)
    {
        remain = 0;
        complete = 0;
        TaskList.forEach(item => (goalName === item.goalName) ? TaskComp(item): complete = complete);
        return  complete/(complete+remain);
    }

    let ProgressBarGoal = []
    function createProgressBarListGoal(goal,index,array)
    {
        let obj = {
            color : goal.color,
            internalContent : <h4> {goal.goalName} </h4>,
            progressborder : Math.round(100*Math.max(new Date().getTime()-goal.goalStart.getTime(),0) / (goal.goalEnd.getTime() - goal.goalStart.getTime())),
            heightborder : 3,
            heightmain: 25,

            progressmain : Math.round(100*goalComp(goal.goalName)),
        }
            ProgressBarGoal.push(obj);
    }
    GoalList.forEach(createProgressBarListGoal);


    return(
        <div>
        <SidebarMenu>
                    <SidebarMenu.Header >
                    <SidebarMenu.Brand>
                <div >  <Calender /> </div>
                    </SidebarMenu.Brand>
                    </SidebarMenu.Header>

        <SidebarMenu.Body class="overflow-auto" style={{height:"900px"}}>
            <div style={{padding:"1%"}}>
                <SidebarMenu.Sub>
                <SidebarMenu.Sub.Toggle bsPrefix="p-1 btn btn-outline-secondary rounded-3">
                <h5 style={{paddingTop:"9px"}}>Goals</h5>
                </SidebarMenu.Sub.Toggle>
                            <SidebarMenu.Sub.Collapse>
                                <SidebarMenu.Nav>
                                    {ProgressBarGoal.map((item,index) =><div style={{padding:"1%"}}><SidebarMenu.Nav.Item><ProgressBar item={item}/></SidebarMenu.Nav.Item></div>)}
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
                                    {ProgressBarList.map((item,index) =><div style={{padding:"1%"}}><SidebarMenu.Nav.Item><ProgressBar item={item}/></SidebarMenu.Nav.Item></div>)}
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
