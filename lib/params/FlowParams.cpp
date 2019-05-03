#include "vapor/FlowParams.h"

using namespace VAPoR;

const std::string FlowParams::_isSteadyTag = "isSteadyTag";
const std::string FlowParams::_velocityMultiplierTag = "velocityMultiplierTag";
const std::string FlowParams::_steadyNumOfStepsTag   = "steadyNumOfStepsTag";
const std::string FlowParams::_seedGenModeTag        = "seedGenModeTag";
const std::string FlowParams::_seedInputFilenameTag  = "seedInputFilenameTag";
const std::string FlowParams::_flowDirectionTag      = "flowDirectionTag";

static RenParamsRegistrar<FlowParams> registrar(FlowParams::GetClassType());

// Constructor
FlowParams::FlowParams(   DataMgr*                 dataManager,
                          ParamsBase::StateSave*   stateSave )
          : RenderParams( dataManager,
                          stateSave, 
                          FlowParams::GetClassType(),
                          3 /* max dim */ )
{
    SetDiagMsg("FlowParams::FlowParams() this=%p", this);
}

FlowParams::FlowParams(   DataMgr*                dataManager, 
                          ParamsBase::StateSave*  stateSave,
                          XmlNode*                node )
       : RenderParams(    dataManager, 
                          stateSave, 
                          node,
                          3 /* max dim */ )
{
    SetDiagMsg("FlowParams::FlowParams() this=%p", this);
}

// Destructor
FlowParams::~FlowParams()
{
    SetDiagMsg( "FlowParams::~FlowParams() this=%p", this );
}


void
FlowParams::SetIsSteady( bool steady)
{
	SetValueLong( _isSteadyTag, "are we using steady advection", long(steady) );
}

bool
FlowParams::GetIsSteady() const
{
	long rv = GetValueLong( _isSteadyTag, long(false) );
    return bool(rv);
}
    
double
FlowParams::GetVelocityMultiplier() const
{
    return GetValueDouble( _velocityMultiplierTag, 1.0 );
}
    
void 
FlowParams::SetVelocityMultiplier( double coeff )
{
    SetValueDouble( _velocityMultiplierTag, "velocity multiplier", coeff );
}

long
FlowParams::GetSteadyNumOfSteps() const
{
    return GetValueLong( _steadyNumOfStepsTag, 0 );
}

void
FlowParams::SetSteadyNumOfSteps( long i )
{
    SetValueLong( _steadyNumOfStepsTag, "num of steps for a steady integration", i );
}

long
FlowParams::GetSeedGenMode() const
{
    return GetValueLong( _seedGenModeTag, 0 );
}

void
FlowParams::SetSeedGenMode( long i )
{
    SetValueLong( _seedGenModeTag, "which mode do we use to generate seeds", i );
}

std::string
FlowParams::GetSeedInputFilename() const
{
    return GetValueString( _seedInputFilenameTag, "" );
}

void
FlowParams::SetSeedInputFilename( std::string& name )
{
    SetValueString( _seedInputFilenameTag, "filename for input seeding list", name ); 
}

long
FlowParams::GetFlowDirection() const
{
    return GetValueLong( _flowDirectionTag, 0 );
}

void
FlowParams::SetFlowDirection( long i )
{
    SetValueLong( _flowDirectionTag, "does flow integration go forward, backward, or bi-directional", i );
}