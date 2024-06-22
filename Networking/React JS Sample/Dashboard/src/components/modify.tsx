import ModifyForm from './modifyForm';

import Button from 'react-bootstrap/Button';
import Modal from 'react-bootstrap/Modal';

function Modify(props:any)
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
        Modify Task
        </Modal.Title>
        </Modal.Header>
        <Modal.Body>

        <ModifyForm GoalList={props.GoalList} apivalue={props.apivalue} task={props.task}/>
        </Modal.Body>
        <Modal.Footer>
        <Button onClick={props.onHide}>Close</Button>
        </Modal.Footer>
        </Modal>
        </>
    );
}



export default Modify;
