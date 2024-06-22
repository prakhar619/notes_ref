import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import { useState }  from 'react';

function TaskForm(props:any)
{
    let goalList:any[] = [...props.goalList];

    const [inputFields,setInputFields] = useState([1]);

    let subtask = 1;
    const newsubtask = () =>{
        setInputFields([...inputFields,++subtask]);
    }

    const remsubtask = () =>{
        subtask -= 1;
        inputFields.pop();
        setInputFields([...inputFields]);
    }

    return(
        <>
        <Form action="/form/addTask" method="post">

            <Form.Group className="mb-3" controlId="TaskForm.TaskName">
            <Form.Control name="api" type="hidden" value={props.apivalue}/>
            </Form.Group>

            <Form.Group className="mb-3" controlId="TaskForm.TaskName">
            <Form.Label>Goal Name</Form.Label>
            <Form.Select name="goalName">
            {goalList.map((goal:any) => <option  value={goal.goalName}>{goal.goalName} </option>)}
            </Form.Select>
            </Form.Group>

            <Form.Group className="mb-3" controlId="TaskForm.TaskName">
                <Form.Label>Task Name</Form.Label>
                <Form.Control name="taskName" type="text" placeholder="" />
            </Form.Group>

            <Row className="mb-3">
                <Form.Group  as={Col} className="mb-3" controlId="TaskForm.Duration">
                <Form.Label>Duration</Form.Label>
                <Form.Control name="taskDuration" type="number" placeholder="in weeks" />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.Start">
                <Form.Label>Start</Form.Label>
                <Form.Control name="taskStart" type="date" placeholder="" />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.End">
                <Form.Label>End</Form.Label>
                <Form.Control name="taskEnd" type="date" placeholder="" />
                </Form.Group>
            </Row>

            <Form.Group className="mb-3" controlId="TaskForm.Priorty">
            <Form.Label>Priorty</Form.Label>
            <Form.Select name="taskPriorty" defaultValue="Low">
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
                <Form.Control name={"subTaskName"+index.toString()} type="text" placeholder={"Subtask "+input.toString()} />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.SubTaskEst">
                <Form.Label>Estimated time</Form.Label>
                <Form.Control name={"est"+index.toString()} type="number" placeholder="in hours" />
                </Form.Group>
                </Row>
                )})
            }
            <div className="d-flex flex-row">
            <Button style={{marginRight:"20px"}} variant="primary" type="button" onClick={newsubtask}> New Subtask </Button>
            <Button variant="danger" type="button" onClick={remsubtask}>Remove Subtask </Button>
            </div>

        <Button variant="primary" type="submit">Submit</Button>
        </Form>
        </>
    );
}

export default TaskForm;
