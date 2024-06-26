import ModifyGoalForm from './modifyGoalForm';

import Button from 'react-bootstrap/Button';
import Modal from 'react-bootstrap/Modal';

function ModifyGoal(props:any)
{
    return(
        <>
        <Modal
        {...props}
        size="lg"

        aria-labelledby="contained-modal-title-vcenter"
        centered
        data-bs-theme="dark"
        >
        <Modal.Header closeButton>
        <Modal.Title id="contained-modal-title-vcenter">
        Modify Goal
        </Modal.Title>
        </Modal.Header>
        <Modal.Body>
        </Modal.Body>
        <ModifyGoalForm GoalList={props.GoalList} apivalue={props.apivalue}/>
        <Modal.Footer>
        <Button onClick={props.onHide}>Close</Button>
        </Modal.Footer>
        </Modal>
        </>
    );
}

export default ModifyGoal;
