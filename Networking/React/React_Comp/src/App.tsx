import ProgressComp from "./components/progressBar";
import NavBar from "./components/searchBar";
import BasicDateCalendar from "./components/calendar";
import AddTask from "./components/addTask";
import AddGoal from "./components/addGoal";
import LoginUser from "./components/loginUser";
import RegisterUser from "./components/registerUser";
import DashBoard from "./components/dashboard";

import Button from 'react-bootstrap/Button';
import Modal from 'react-bootstrap/Modal';
import React from 'react'

import { ThemeProvider, createTheme } from '@mui/material/styles';
import CssBaseline from '@mui/material/CssBaseline';


const darkTheme = createTheme({
  palette: {
    mode: 'dark',
  },
});

function App() {

//   <LoginUser/>

/*   <ThemeProvider theme={darkTheme}>
      <CssBaseline />

      <DashBoard />

   </ThemeProvider>
*/

  const [TaskModal, setTaskModal] = React.useState(false);
  const [GoalModal, setGoalModal] = React.useState(false);



  return (
  <>
  <div style={{padding:"1%"}}>
   <RegisterUser/>
  </div>
  </>
  );
}
export default App;
