import GoalForm from './goalForm';

import Button from 'react-bootstrap/Button';
import Modal from 'react-bootstrap/Modal';

function AddGoal(props:any)
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
        New Goal
        </Modal.Title>
        </Modal.Header>
        <Modal.Body>

        <GoalForm apivalue={props.apivalue}/>
        </Modal.Body>
        <Modal.Footer>
        <Button onClick={props.onHide}>Close</Button>
        </Modal.Footer>
        </Modal>
        </>
    );
}



export default AddGoal;
