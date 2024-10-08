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

#include "mcptt-floor-msg-sink.h"

#include "mcptt-entity-id.h"
#include "mcptt-floor-queue.h"

#include <ns3/log.h>
#include <ns3/object.h>
#include <ns3/ptr.h>
#include <ns3/type-id.h>

namespace ns3
{

namespace psc
{

NS_LOG_COMPONENT_DEFINE("McpttFloorMsgSink");

/** McpttFloorMsgSink - begin **/
McpttFloorMsgSink::McpttFloorMsgSink()
{
    NS_LOG_FUNCTION(this);
}

McpttFloorMsgSink::~McpttFloorMsgSink()
{
    NS_LOG_FUNCTION(this);
}

void
McpttFloorMsgSink::Receive(const McpttFloorMsg& msg)
{
}

void
McpttFloorMsgSink::Receive(const McpttMediaMsg& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorAck(const McpttFloorMsgAck& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorDeny(const McpttFloorMsgDeny& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorGranted(const McpttFloorMsgGranted& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorIdle(const McpttFloorMsgIdle& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorQueuePositionRequest(const McpttFloorMsgQueuePositionRequest& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorQueuePositionInfo(const McpttFloorMsgQueuePositionInfo& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorRelease(const McpttFloorMsgRelease& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorRequest(const McpttFloorMsgRequest& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorRevoke(const McpttFloorMsgRevoke& msg)
{
}

void
McpttFloorMsgSink::ReceiveFloorTaken(const McpttFloorMsgTaken& msg)
{
}

void
McpttFloorMsgSink::ReceiveMedia(const McpttMediaMsg& msg)
{
}

/** McpttFloorMsgSink - end **/

} // namespace psc
} // namespace ns3
