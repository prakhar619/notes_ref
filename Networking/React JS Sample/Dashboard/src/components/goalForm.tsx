import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';

function GoalForm(props:any)
{
    return(
        <>
        <Form action="/form/addGoal" method="post">

        <Form.Group className="mb-3" controlId="TaskForm.TaskName">
        <Form.Control name="api" type="hidden" value={props.apivalue} />
        </Form.Group>

        <Form.Group className="mb-3" controlId="GoalForm.GoalName">
        <Form.Label>Goal Name</Form.Label>
        <Form.Control name="goalName" type="text" placeholder="" />
        </Form.Group>

        <Row className="mb-3">
        <Form.Group  as={Col} className="mb-3" controlId="GoalForm.Duration">
        <Form.Label>Duration</Form.Label>
        <Form.Control name="goalDuration" type="number" placeholder="in weeks" />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="GoalForm.Start">
        <Form.Label>Start</Form.Label>
        <Form.Control name="goalStart" type="date" placeholder="" />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="GoalForm.End">
        <Form.Label>End</Form.Label>
        <Form.Control name="goalEnd" type="date" placeholder="" />
        </Form.Group>
        </Row>

        <Form.Group  className="mb-3" controlId="GoalForm.Success">
        <Form.Label>Success Crit</Form.Label>
        <Form.Control name="successCrit" as="textarea" placeholder="" />
        </Form.Group>

        <Button variant="primary" type="submit">
        Submit
        </Button>
        </Form>
        </>
    );
}

export default GoalForm;
