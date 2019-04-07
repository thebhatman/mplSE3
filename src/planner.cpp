#include "MotionPlanner.h"

#include "ompl/base/StateSpace.h"
#include "ompl/base/spaces/RealVectorStateSpace.h"
#include "ompl/base/spaces/SO3StateSpace.h"

using namespace cv;
using namespace std;
namespace ob = ompl::base;
namespace og = ompl::geometric;

typedef struct 
{
  double x;
  double y;
  double z;
}point;

std::vector<point> vect,vect1;

Planning::Planning(vector<pos> &v,int n)
{
  init(v,n);
}


void Planning::init(vector<pos> &v,int n)
{

  /*Set xStart, yStart, zStart, xGoal, yGoal, zGoal, and boundary of space, obstacle locations here.

  // xStart=0.0;
  // yStart=0.0;
  // xGoal=0.0;
  // yGoal=0.0;
  // stepSize=0.0;
  // xLeft=0.0;
  // xRight=0.0;
  // yTop=0.0;
  // yBottom=0.0;
  // selector=0;  Selects Path planning algorithm


  // numObstacles = n;
  // xc = new double[numObstacles];
  // yc = new double[numObstacles];
  // zc = new double[numObstacles];

  // for(int i=0;i<n;i++){
  //   xc[i] = v[i].x;
  //   yc[i] = v[i].y;
  //   zc[i] = v[i].z;
  // }
  */
}


void Planning::CreateObstacle()
{
  for(int i=0;i<numObstacles;i++)
  {
    //Create obstacles here
  }
}


bool Planning::isStateValid1(const ob::State *state)
{
  const ob::SE3StateSpace::StateType *state_3d= state->as<ob::SE3StateSpace::StateType>();
  const double &x(state_3d->getX()), &y(state_3d->getY()), &z(state_3d->getZ());
  //Condition for invalid state. Change the threshold accordingly.
  for (int i = 0; i < numObstacles; ++i){
    if (sqrt(pow((xc[i]-x),2) + pow((yc[i]-y),2) + pow((zc[i] - z), 2))<=10.0){
      return false;
    }
  }

  return true;
}


bool Planning::plan(unsigned int start_row, unsigned int start_col, unsigned int goal_row, unsigned int goal_col){
  //Todo
}

void Planning::recordSolution(){

}

bool Planning::isStateValid(const ob::State *state) const {
  const int w = std::min((int)state->as<ob::RealVectorStateSpace::StateType>()->values[0], maxWidth_);
  const int h = std::min((int)state->as<ob::RealVectorStateSpace::StateType>()->values[1], maxHeight_);
  const int d = std::min((int)state->as<ob::RealVectorStateSpace::StateType>()->values[2], maxDepth_);
  for (int i = 0; i < numObstacles; ++i){
    if (sqrt(pow((xc[i]-w),2) + pow((yc[i]-h),2) + pow((zc[i] - d), 2))<=10.0){
      return false;
    }
  }
  return true;
}



void Planning::planSimple(){
  auto space(std::make_shared<ob::RealVectorStateSpace>());
  //Add appropriate Dimensions of Space.
  space->addDimension(0.0, 100.0);
  space->addDimension(0.0, 100.0);
  space->addDimension(0.0, 100.0); 
  maxWidth_ = 100;
  maxHeight_ = 100;
  ss_ = std::make_shared<og::SimpleSetup>(space);
  ss_->setStateValidityChecker([this](const ob::State *state) {return isStateValid(state);});
  space->setup();
  ss_->getSpaceInformation()->setStateValidityCheckingResolution(1.0 / space->getMaximumExtent());
  //Choose Path Planing Algorithm here.
  //ss_->setPlanner(make_shared<og::LazyRRT>(ss_->getSpaceInformation()));
}


void Planning::planWithSimpleSetup()
{
  // Construct the state space where we are planning
  ob::StateSpacePtr space(new ob::SE3StateSpace());

  ob::RealVectorBounds bounds(3);
  bounds.setLow(0,xLeft);
  bounds.setHigh(0,xRight);
  bounds.setLow(1,yBottom);
  bounds.setHigh(1,yTop);
  bounds.setLow(2, zMin);
  bounds.setHigh(2, zMax);

  space->as<ob::SE3StateSpace>()->setBounds(bounds);

  og::SimpleSetup ss(space);

  // Setup the StateValidityChecker
  ss.setStateValidityChecker(boost::bind(&Planning::isStateValid1, this, _1));

  // Setup Start and Goal
  ob::ScopedState<ob::SE3StateSpace> start(space);
  start->setXYZ(xStart, yStart, zStart);

  ob::ScopedState<ob::SE3StateSpace> goal(space);
  goal->setXYZ(xGoal, yGoal, zGoal);

  ss.setStartAndGoalStates(start, goal);

  if(selector == 1){
    ob::PlannerPtr planner(new og::PRM(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 2){
    ob::PlannerPtr planner(new og::RRT(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 3){
    ob::PlannerPtr planner(new og::RRTConnect(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 4){
    ob::PlannerPtr planner(new og::RRTstar(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 5){
    ob::PlannerPtr planner(new og::LBTRRT(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 6){
    ob::PlannerPtr planner(new og::LazyRRT(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 7){
    ob::PlannerPtr planner(new og::TRRT(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 8){
    ob::PlannerPtr planner(new og::pRRT(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }else if(selector == 9){
    ob::PlannerPtr planner(new og::EST(ss.getSpaceInformation()));
    ss.setPlanner(planner);
  }

  ob::PlannerStatus solved = ss.solve(5);

  if (solved)
  {
    ss.getSolutionPath();
    ss.simplifySolution();

    //Print the solution path to a file
    //std::ofstream ofs("path.dat");
    //ss.getSolutionPath().printAsMatrix(ofs); 

    og::PathGeometric &p = ss.getSolutionPath();
    p.interpolate();

  }
  else
    cout << "No solution found" << endl;
}

void Planning::drawPath(){
  //Show Final Path 
}

void Planning::output(){
  
}