function ProgressBar(prop:any)
{
//     return a div elem
    let color = prop.item.color;
    let internalContent = prop.item.internalContent;
    let progressborder = prop.item.progressborder;
    let progressmain = prop.item.progressmain;

    let heightborder = prop.item.heightborder;
    let heightmain = prop.item.heightmain;

    return(
    <>
        <div style={{padding:"0.5%"}}>
            <div className="progress" role="progressbar" style={{height: heightborder.toString()+"px"}}>
                <div className={"progress-bar "} style={{width: progressborder.toString()+'%',backgroundColor:color.border}}></div>
            </div>

            <div className="progress" role="progressbar" style={{height: heightmain+"px"}}>
                <div className={'progress-bar progress-bar-striped progress-bar-animated '}  style={{width: progressmain.toString()+'%',backgroundColor:color.main}}>
                    <div style={{paddingTop:"14px",color:"#212f3d"}}>{internalContent}</div>
                </div>
            </div>

            <div className="progress" role="progressbar" style={{height: heightborder.toString()+"px"}}>
            <div className={"progress-bar "} style={{width: progressborder.toString()+'%',backgroundColor:color.border}}></div>
            </div>
        </div>
    </>
    );
}

export default ProgressBar;
