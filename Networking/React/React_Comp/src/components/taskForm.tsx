import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import { useState }  from 'react';

function TaskForm(prop)
{
    let goalList = [...prop.goalList];

    const [inputFields,setInputFields] = useState([{subTaskName:'',est:''}]);

    const newsubtask = () =>{
        setInputFields([...inputFields,{subTaskName:'',est:''}]);
        subTaskNum += 1;
    }

    return(
        <>
        <Form>
            <Form.Group className="mb-3" controlId="TaskForm.TaskName">
            <Form.Label>Goal Name</Form.Label>
            <Form.Select>
            {goalList.map( (goal,index) => <option value={goal.goalName}>{goal.goalName} </option>)}
            </Form.Select>
            </Form.Group>

            <Form.Group className="mb-3" controlId="TaskForm.TaskName">
                <Form.Label>Task Name</Form.Label>
                <Form.Control type="text" placeholder="" />
            </Form.Group>

            <Row className="mb-3">
                <Form.Group  as={Col} className="mb-3" controlId="TaskForm.Duration">
                <Form.Label>Duration</Form.Label>
                <Form.Control type="number" placeholder="in weeks" />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.Start">
                <Form.Label>Start</Form.Label>
                <Form.Control type="date" placeholder="" />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.End">
                <Form.Label>End</Form.Label>
                <Form.Control type="date" placeholder="" />
                </Form.Group>
            </Row>

            <Form.Group className="mb-3" controlId="TaskForm.Priorty">
            <Form.Label>Priorty</Form.Label>
            <Form.Select defaultValue="Low">
            <option>Low</option>
            <option>Med</option>
            <option>High</option>
            </Form.Select>
            </Form.Group>


            {inputFields.map((input,index)=>{ return (<Row className="mb-3" key={index}>
                <Form.Group  as={Col} className="mb-3" controlId={"TaskForm.SubTaskName"}>
                <Form.Label>Subtask Name</Form.Label>
                <Form.Control type="text" placeholder="" />
                </Form.Group>

                <Form.Group as={Col} className="mb-3" controlId="TaskForm.SubTaskEst">
                <Form.Label>Estimated time</Form.Label>
                <Form.Control type="number" placeholder="in hours" />
                </Form.Group>
                </Row>  ) } )   }

            <Button variant="primary" type="button" onClick={newsubtask}> New Subtask </Button>
        <br/><br/>
        <Button variant="primary" type="submit">Submit</Button>
        </Form>
        </>
    );
}

export default TaskForm;
