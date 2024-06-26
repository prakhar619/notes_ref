import DashBoard from "./components/dashboard.tsx";

import { ThemeProvider, createTheme } from '@mui/material/styles';
import CssBaseline from '@mui/material/CssBaseline';

import {useState,useEffect} from 'react';


const darkTheme = createTheme({
  palette: {
    mode: 'dark',
  },
});

function App() {
  const [User, setUser] = useState(null);
  const [TaskList, setTaskList] = useState(null);
  const [GoalList, setGoalList] = useState(null);
  let apivalue = document.cookie.split('; ').filter(row => row.startsWith('api=')).map(c=>c.split('=')[1])[0]
  if(apivalue === undefined)
  {
    apivalue="6673460c16183d29e723a22f";
  }
  useEffect(() => {
    fetch('http://localhost:5000/UserData/'+apivalue.toString())
    .then(res => res.json())
    .then(User => setUser(User))
  }, []);

  useEffect(() => {
    fetch('http://localhost:5000/TaskListData/'+apivalue.toString())
    .then(res => res.json())
    .then(TaskList => setTaskList(TaskList))
  }, []);

  useEffect(() => {
    fetch('http://localhost:5000/GoalListData/'+apivalue.toString())
    .then(res => res.json())
    .then(GoalList => setGoalList(GoalList))
  }, []);


  return (
  <>
  <div style={{padding:"1%"}}>

   <ThemeProvider theme={darkTheme}>
      <CssBaseline />
      {apivalue.toString() === "default" ? <h1>Sign in to set your own goal</h1>: null}
      <DashBoard TaskList={TaskList} GoalList={GoalList} User={User} apivalue={apivalue}/>

   </ThemeProvider>

  </div>
  </>
  );
}
export default App;
