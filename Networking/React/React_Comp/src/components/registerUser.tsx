import BackGround from './backgroundRegister';

import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import {
    MDBBtn,
    MDBContainer,
    MDBCard,
    MDBCardBody,
    MDBCardImage,
    MDBRow,
    MDBCol,
    MDBIcon,
    MDBInput
} from 'mdb-react-ui-kit';

import RegisterPic from './../assets/register.jpg';

function RegisterUser()
{
    return(
        <>
        <BackGround  entered={false}/>
        <MDBContainer className="my-5">

        <MDBCard>
        <MDBRow className='g-0'>

        <MDBCol md='6'>
        <MDBCardImage src={RegisterPic}   alt="login form" className='rounded-start w-100'/>
        </MDBCol>

        <MDBCol md='6'>
        <MDBCardBody className='d-flex flex-column'>


        <div className='d-flex flex-row mt-2'>
        <MDBIcon fas icon="cubes fa-3x me-3" style={{ color: '#ff6219' }}/>
        <span className="h1 fw-bold mb-0">WRKFLOW</span>
        </div>

        <h5 className="fw-normal my-4 pb-3" style={{letterSpacing: '1px'}}>Sign Up</h5>
        <Form>
        <Row  className="mb-3">
        <Form.Group as={Col} className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>First Name</Form.Label>
        <Form.Control type="text" placeholder="" />
        </Form.Group>

        <Form.Group as={Col} className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label>Last Name</Form.Label>
        <Form.Control type="text" placeholder="" />
        </Form.Group>
        </Row>

        <Form.Group  className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label> Email </Form.Label>
        <Form.Control type="email" placeholder="" />
        </Form.Group>


        <Form.Group  className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label> Phone No </Form.Label>
        <Form.Control type="text" placeholder="" />
        </Form.Group>

        <Form.Group  className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label> username </Form.Label>
        <Form.Control type="text" placeholder="" />
        </Form.Group>

        <Form.Group  className="mb-3" controlId="TaskForm.TaskName">
        <Form.Label> Password </Form.Label>
        <Form.Control type="password" placeholder="" />
        </Form.Group>

        <Button variant="primary" type="submit">Submit</Button>
        </Form>
        </MDBCardBody>
        </MDBCol>

        </MDBRow>
        </MDBCard>

        </MDBContainer>
        </>
    );
}

export default RegisterUser;
