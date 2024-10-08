/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * NIST-developed software is provided by NIST as a public service. You may
 * use, copy and distribute copies of the software in any medium, provided that
 * you keep intact this entire notice. You may improve, modify and create
 * derivative works of the software or any portion of the software, and you may
 * copy and distribute such modifications or works. Modified works should carry
 * a notice stating that you changed the software and should note the date and
 * nature of any such change. Please explicitly acknowledge the National
 * Institute of Standards and Technology as the source of the software.
 *
 * NIST-developed software is expressly provided "AS IS." NIST MAKES NO
 * WARRANTY OF ANY KIND, EXPRESS, IMPLIED, IN FACT OR ARISING BY OPERATION OF
 * LAW, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT AND DATA ACCURACY. NIST
 * NEITHER REPRESENTS NOR WARRANTS THAT THE OPERATION OF THE SOFTWARE WILL BE
 * UNINTERRUPTED OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED. NIST
 * DOES NOT WARRANT OR MAKE ANY REPRESENTATIONS REGARDING THE USE OF THE
 * SOFTWARE OR THE RESULTS THEREOF, INCLUDING BUT NOT LIMITED TO THE
 * CORRECTNESS, ACCURACY, RELIABILITY, OR USEFULNESS OF THE SOFTWARE.
 *
 * You are solely responsible for determining the appropriateness of using and
 * distributing the software and you assume all risks associated with its use,
 * including but not limited to the risks and costs of program errors,
 * compliance with applicable laws, damage to or loss of data, programs or
 * equipment, and the unavailability or interruption of operation. This
 * software is not intended to be used in any situation where a failure could
 * cause risk of injury or damage to property. The software developed by NIST
 * employees is not subject to copyright protection within the United States.
 */

#include "mcptt-pusher-orchestrator-interface.h"

#include "mcptt-pusher.h"

#include <ns3/log.h>
#include <ns3/ptr.h>
#include <ns3/simulator.h>
#include <ns3/type-id.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("McpttPusherOrchestratorInterface");

namespace psc
{

NS_OBJECT_ENSURE_REGISTERED(McpttPusherOrchestratorInterface);

TypeId
McpttPusherOrchestratorInterface::GetTypeId()
{
    static TypeId tid =
        TypeId("ns3::psc::McpttPusherOrchestratorInterface")
            .SetParent<Object>()
            .AddTraceSource(
                "PttInterarrivalTimeTrace",
                "The trace for capturing PTT interarrival times.",
                MakeTraceSourceAccessor(&McpttPusherOrchestratorInterface::m_pttIatTrace),
                "ns3::Time::TracedCallback")
            .AddTraceSource(
                "PttDurationTrace",
                "The trace for capturing PTT durations.",
                MakeTraceSourceAccessor(&McpttPusherOrchestratorInterface::m_pttDurationTrace),
                "ns3::Time::TracedCallback");

    return tid;
}

McpttPusherOrchestratorInterface::McpttPusherOrchestratorInterface()
    : Object()
{
    NS_LOG_FUNCTION(this);
}

McpttPusherOrchestratorInterface::~McpttPusherOrchestratorInterface()
{
    NS_LOG_FUNCTION(this);
}

void
McpttPusherOrchestratorInterface::StartAt(const Time& t)
{
    NS_LOG_FUNCTION(this << t);

    m_startEvent = Simulator::Schedule(t, &McpttPusherOrchestratorInterface::Start, this);
}

void
McpttPusherOrchestratorInterface::StopAt(const Time& t)
{
    NS_LOG_FUNCTION(this << t);

    m_stopEvent = Simulator::Schedule(t, &McpttPusherOrchestratorInterface::Stop, this);
}

void
McpttPusherOrchestratorInterface::DoDispose()
{
    NS_LOG_FUNCTION(this);

    m_startEvent.Cancel();
    m_stopEvent.Cancel();
}

void
McpttPusherOrchestratorInterface::TracePttIat(const uint32_t userId, const Time& iat)
{
    NS_LOG_FUNCTION(this);

    m_pttIatTrace(userId, iat);
}

void
McpttPusherOrchestratorInterface::TracePttDuration(const uint32_t userId, const Time& duration)
{
    NS_LOG_FUNCTION(this);

    m_pttDurationTrace(userId, duration);
}

} // namespace psc
} // namespace ns3
