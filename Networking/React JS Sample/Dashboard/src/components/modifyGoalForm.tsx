import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import { useState }  from 'react';

function ModifyGoalForm(props:any)
{
    let goalList:any[] = [...props.GoalList];
    let apivalue = props.apivalue;

    let index = 0; let goalId = goalList[index]._id;
    const [name,setname] = useState(goalList[index].goalName);
    const [start,setstart] = useState(goalList[index].goalStart);
    const [end,setend] = useState(goalList[index].goalEnd);
    const [duration,setduration] = useState(goalList[index].goalDuration);
    const [succ,setsucc] = useState(goalList[index].successCrit);

    function nameChange(e:any)
    {
        setname(e.target.value);
    }
    function durChange(e:any)
    {
        setduration(e.target.value);
    }
    function startChange(e:any)
    {
        setstart(new Date(e.target.value));
    }
    function endChange(e:any)
    {
        setend(new Date(e.target.value));
    }
    function succChange(e:any)
    {
        setsucc(e.target.value);
    }



    function selectHandler(e:any)
    {
        let goalName = e.target.value;
        goalList.forEach((goal:any) =>{
            if(goal.goalName === goalName)
            {
                setname(goal.goalName);
                setduration(goal.goalDuration);
                setstart(goal.goalStart);
                setend(goal.goalEnd);
                setsucc(goal.successCrit);
                goalId = goal._id;
            }
        })
    }

    return(
        <>
        <Form  action="/form/modifyGoal" method="post" style={{padding:"2%"}}>

        <Form.Group className="" controlId="TaskForm.TaskName">
        <Form.Control name="api" type="hidden" value={apivalue}/>
        <Form.Control name="goalId" type="hidden" value={goalId}/>
        </Form.Group>


        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>Goal</Form.Label>
        <Form.Select  name="goal" onChange={selectHandler}>
        {goalList.map((goal:any) => <option  value={goal.goalName} >{goal.goalName} </option>)}
        </Form.Select>
        </Form.Group>

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>Goal Name</Form.Label>
        <Form.Control name="goalName" type="text" value={name}  onChange={nameChange}/>
        </Form.Group>

        <Row className="mb-3">
        <Form.Group  as={Col} className="mb-3" controlId="TaskForm.Duration">
        <Form.Label>Duration</Form.Label>
        <Form.Control name="goalDuration" type="number" value={duration}  onChange={durChange} />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="TaskForm.Start">
        <Form.Label>Start</Form.Label>
        <Form.Control name="goalStart" type="date" value={start.toISOString().substr(0,10)} onChange={startChange}/>
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="TaskForm.End">
        <Form.Label>End</Form.Label>
        <Form.Control name="goalEnd" type="date" value={end.toISOString().substr(0,10)} onChange={endChange}/>
        </Form.Group>
        </Row>

        <Form.Group  className="mb-3" controlId="GoalForm.Success">
        <Form.Label>Success Crit</Form.Label>
        <Form.Control  name="successCrit" as="textarea" value={succ} onChange={succChange} />
        </Form.Group>

        <Form.Group  className="mb-4" controlId="GoalForm.Success">
        <Form.Check defaultChecked={false} >
        <Form.Check.Input  name="completed" value="true" isValid />
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

export default ModifyGoalForm;
