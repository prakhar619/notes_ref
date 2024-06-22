import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import { useState }  from 'react';

function ModifyForm(props:any)
{
    let goalList:any[] = [...props.GoalList];
    let task:any = props.task;
    let apivalue = props.apivalue;

    const [inputFields,setInputFields] = useState(props.task.subTaskList);

    let subtask = {subTaskName:"",est:0,completed:false};
    const newsubtask = () =>{
        setInputFields([...inputFields,subtask]);
    }

    const remsubtask = () =>{
        inputFields.pop();
        setInputFields([...inputFields]);
    }

    return(
        <>
        <Form  action="/form/modifyTask" method="post">

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Control name="api" type="hidden" value={apivalue}/>
        </Form.Group>

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Control name="taskId" type="hidden" value={props.task._id}/>
        </Form.Group>

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>Goal Name</Form.Label>
        <Form.Select name="goalName">
        {goalList.map((goal:any) => <option  value={goal.goalName} selected={(goal.goalName === task.goalName)}>{goal.goalName} </option>)}
        </Form.Select>
        </Form.Group>

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>Task Name</Form.Label>
        <Form.Control name="taskName" type="text" defaultValue={task.taskName} />
        </Form.Group>

        <Row className="mb-3">
        <Form.Group  as={Col} className="mb-3" controlId="TaskForm.Duration">
        <Form.Label>Duration</Form.Label>
        <Form.Control name="taskDuration" type="number" defaultValue={task.taskDuration} />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="TaskForm.Start">
        <Form.Label>Start</Form.Label>
        <Form.Control name="taskStart" type="date" defaultValue={task.taskStart.toISOString().substr(0,10)} />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="TaskForm.End">
        <Form.Label>End</Form.Label>
        <Form.Control name="taskEnd" type="date" defaultValue={task.taskEnd.toISOString().substr(0,10)}/>
        </Form.Group>
        </Row>

        <Form.Group className="mb-3" controlId="TaskForm.Priorty">
        <Form.Label>Priorty</Form.Label>
        <Form.Select name="taskPriorty" >
        <option>Low</option>
        <option>Med</option>
        <option>High</option>
        </Form.Select>
        </Form.Group>


        {inputFields.map((input:any,index:number)=>{
            return (
                <Row className="mb-3">
                <Form.Group  as={Col} className="mb-3" controlId={"TaskForm.SubTaskName"}>
                <Form.Label>Subtask Name</Form.Label>
                <Form.Control name={"subTaskName"+index.toString()} type="text" defaultValue={input.subTaskName} />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.SubTaskEst">
                <Form.Label>Estimated time</Form.Label>
                <Form.Control name={"est"+index.toString()} type="number" defaultValue={input.est} />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.SubTaskEst">
                <Form.Label>Done</Form.Label>
                <Form.Select name={"completed"+index.toString()}  defaultValue={input.completed}>
                <option value="true">Yes</option>
                <option value="false">No</option>
                </Form.Select>

                </Form.Group>
                </Row>

            )})
        }
        <div className="d-flex flex-row">
        <Button style={{marginRight:"20px"}} variant="primary" type="button" onClick={newsubtask}> New Subtask </Button>
        <Button variant="danger" type="button" onClick={remsubtask}>Remove Subtask </Button>
        </div>
        <br/><br/>
        <Form.Group  className="mb-4" controlId="GoalForm.Success">
        <Form.Check    defaultChecked={false} >
        <Form.Check.Input name="completed" value="true" isValid />
        <Form.Check.Label>Completed</Form.Check.Label>
        </Form.Check>
        </Form.Group>
        <div className="d-flex flex-row">
        <Button style={{marginRight:"20px"}} variant="primary" type="submit">Submit</Button>
        <Button variant="danger" name="delete" value="true" type="submit">Delete</Button>
        </div>
        </Form>

        </>
    );
}

export default ModifyForm;
