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

#ifndef MCPTT_SERVER_CALL_MACHINE_H
#define MCPTT_SERVER_CALL_MACHINE_H

#include "mcptt-call-msg-field.h"
#include "mcptt-call-msg.h"
#include "mcptt-call-type-machine.h"
#include "mcptt-emerg-alert-machine.h"
#include "mcptt-media-msg.h"

#include <ns3/object.h>
#include <ns3/sip-header.h>
#include <ns3/type-id.h>

namespace ns3
{

namespace psc
{

class McpttServerCall;

/**
 * \ingroup mcptt
 *
 * This interface is used to construct a common API for the MCPTT server
 * entities performing server call control described in TS 24.379.
 */
class McpttServerCallMachine : public Object
{
  public:
    /**
     * Gets the type ID of the McpttServerCallMachine class.
     * \returns The type ID.
     */
    static TypeId GetTypeId();
    /**
     * Creates an instance of the McpttServerCallMachine class.
     */
    McpttServerCallMachine();
    /**
     * The destructor of the McpttServerCallMachine class.
     */
    ~McpttServerCallMachine() override;
    /**
     * Accepts the call.
     */
    virtual void AcceptCall() = 0;
    /**
     * Begins an emergency alert.
     */
    virtual void BeginEmergAlert() = 0;
    /**
     * Cancels an emergency alert.
     */
    virtual void CancelEmergAlert() = 0;
    /**
     * Downgrades the call type.
     */
    virtual void DowngradeCallType() = 0;
    /**
     * Gets the ID of the user that started the call.
     * \returns The MCPTT user ID.
     */
    virtual uint32_t GetCallerUserId() const = 0;
    /**
     * Gets the ID of the call.
     * \returns The call ID.
     */
    virtual McpttCallMsgFieldCallId GetCallId() const = 0;
    /**
     * Gets the call type.
     * \returns The call type.
     */
    virtual McpttCallMsgFieldCallType GetCallType() const = 0;
    /**
     * Gets the server's user ID.
     * \returns The user ID.
     */
    virtual uint32_t GetUserId() const = 0;
    /**
     * Gets the type ID of this McpttServerCallMachine instance.
     * \returns The type ID.
     */
    TypeId GetInstanceTypeId() const override;
    /**
     * Gets the pointer to the server call.
     * \returns The pointer to the server call.
     */
    virtual Ptr<McpttServerCall> GetServerCall() const = 0;
    /**
     * Gets the ID of the current state.
     * \returns The state ID.
     */
    virtual McpttEntityId GetStateId() const = 0;
    /**
     * Indicates if the call is active.
     * \returns True, if the call is active.
     */
    virtual bool IsCallOngoing() const = 0;
    /**
     * Indicates if this is a group call.
     * \param grpId The particular group ID to check for when greater than 0.
     * \returns True, if this call is a group call; otherwise, false.
     */
    virtual bool IsGrpCall(uint32_t grpId = 0) const = 0;
    /**
     * Indicates if this is a private call.
     * \param userId The particular user ID to check for when greater than 0.
     * \returns True, if this call is a private call; otherwise, false.
     */
    virtual bool IsPrivateCall(uint32_t userId = 0) const = 0;
    /**
     * Receives a call control packet
     * \param pkt The packet received (without SIP header).
     * \param hdr The (deserialized) SIP header
     */
    virtual void ReceiveCallPacket(Ptr<Packet> pkt, const sip::SipHeader& hdr) = 0;
    /**
     * Receives a media message.
     * \param msg The message to receive.
     */
    virtual void Receive(const McpttMediaMsg& msg) = 0;
    /**
     * Rejects the call.
     */
    virtual void RejectCall() = 0;
    /**
     * Sets the callback used to indicate that a new call exists.
     * \param newCallCb The callback.
     */
    virtual void SetNewCallCb(const Callback<void, uint16_t> newCallCb) = 0;
    /**
     * Sets the server call pointer.
     * \param call The pointer back to the server call object.
     */
    virtual void SetServerCall(Ptr<McpttServerCall> call) = 0;
    /**
     * Sets the userId to use for the server.
     * Normally, a SIP URI (string) but the model presently
     * uses integers in place of URIs
     * \param userId The user ID.
     */
    virtual void SetUserId(uint32_t userId) = 0;
    /**
     * Starts the state machine.
     */
    virtual void Start() = 0;
    /**
     * Stops the state machine.
     */
    virtual void Stop() = 0;
    /**
     * Upgrades the call type.
     * \param callType The call type value.
     */
    virtual void UpgradeCallType(uint8_t callType) = 0;
    /**
     * TracedCallback signature for state change traces
     * \param [in] userId User ID
     * \param [in] callId Call ID
     * \param [in] selected Indicator whether the call is selected by the client
     * \param [in] typeId Type ID of the class reporting the change
     * \param [in] oldStateName Name of the old state
     * \param [in] newStateName Name of the new state
     */
    typedef void (*StateChangeTracedCallback)(uint32_t userId,
                                              uint16_t callId,
                                              const std::string& selected,
                                              const std::string& typeId,
                                              const std::string& oldStateName,
                                              const std::string& newStateName);
};

/**
 * \ingroup mcptt
 *
 * A class used to represent a group call call machine.
 */
class McpttServerCallMachineGrp : public McpttServerCallMachine
{
  public:
    /**
     * Gets the type Id of the McpttServerCallMachineGrp class.
     * \returns The type ID.
     */
    static TypeId GetTypeId();
    /**
     * Creates an instance of the McpttServerCallMachineGrp class.
     */
    McpttServerCallMachineGrp();
    /**
     * The destructor of the McpttServerCallMachineGrp class.
     */
    ~McpttServerCallMachineGrp() override;
    /**
     * Sets the group ID.
     * \param grpId The group ID.
     */
    virtual void SetGrpId(uint32_t grpId) = 0;
    /**
     * Gets the group ID.
     * \returns The group ID.
     */
    virtual McpttCallMsgFieldGrpId GetGrpId() const = 0;
    /**
     * Gets the type ID of this instance.
     * \returns The type ID.
     */
    TypeId GetInstanceTypeId() const override;
    /**
     * Indicates if this is a group call.
     * \param grpId The particular group ID to check for when greater than 0.
     * \returns True, if this a group call; otherwise, false.
     */
    bool IsGrpCall(uint32_t grpId = 0) const override;
    /**
     * Indicates if this is a private call.
     * \param userId The particular user ID to check for when greater than 0.
     * \returns True, if this is a private call; otherwise, false.
     */
    bool IsPrivateCall(uint32_t userId = 0) const override;
};

/**
 * \ingroup mcptt
 *
 * A class used to represent a null MCPTT call machine.
 */
class McpttServerCallMachineNull : public McpttServerCallMachine
{
  public:
    /**
     * Gets The null state ID.
     * \returns The state ID.
     */
    static McpttEntityId GetNullStateId();
    /**
     * Gets the type ID of the McpttServerCallMachineNull class.
     * \returns The type ID.
     */
    static TypeId GetTypeId();
    /**
     * Creates an instance of the McpttServerCallMachineNull class.
     */
    McpttServerCallMachineNull();
    /**
     * The destructor of the McpttServerCallMachineNull class.
     */
    ~McpttServerCallMachineNull() override;
    /**
     * Accepts the call.
     */
    void AcceptCall() override;
    /**
     * Begins an emergency alert.
     */
    void BeginEmergAlert() override;
    /**
     * Cancels an emergency alert.
     */
    void CancelEmergAlert() override;
    /**
     * Downgrades the call type.
     */
    void DowngradeCallType() override;
    /**
     * Gets the ID of the user that started the call.
     * \returns The MCPTT user ID.
     */
    uint32_t GetCallerUserId() const override;
    /**
     * Gets the ID of the call.
     * \returns The call ID.
     */
    McpttCallMsgFieldCallId GetCallId() const override;
    /**
     * Gets the call type.
     * \returns The call type.
     */
    McpttCallMsgFieldCallType GetCallType() const override;
    /**
     * Gets the user ID.
     * \returns The user ID.
     */
    uint32_t GetUserId() const override;
    /**
     * Gets the type ID of this McpttServerCallMachineNull instance.
     * \returns The type ID.
     */
    TypeId GetInstanceTypeId() const override;
    /**
     * Gets the pointer to the server call.
     * \returns The pointer to the server call.
     */
    Ptr<McpttServerCall> GetServerCall() const override;
    /**
     * Gets the ID of the current state.
     * \returns The state ID.
     */
    McpttEntityId GetStateId() const override;
    /**
     * Indicates if the call is active.
     * \returns True, if the call is active.
     */
    bool IsCallOngoing() const override;
    /**
     * Indicates if this is a group call.
     * \param grpId The particular group ID to check for when greater than 0.
     * \returns True, if this a group call; otherwise, false.
     */
    bool IsGrpCall(uint32_t grpId = 0) const override;
    /**
     * Indicates if this is a private call.
     * \param userId The particular user ID to check for when greater than 0.
     * \returns True, if this a private call; otherwise, false.
     */
    bool IsPrivateCall(uint32_t userId = 0) const override;
    /**
     * Receives a call control packet
     * \param pkt The packet received (without SIP header).
     * \param hdr The (deserialized) SIP header
     */
    void ReceiveCallPacket(Ptr<Packet> pkt, const sip::SipHeader& hdr) override;
    /**
     * Receives a media message.
     * \param msg The message to receive.
     */
    void Receive(const McpttMediaMsg& msg) override;
    /**
     * Rejects the call.
     */
    void RejectCall() override;
    /**
     * Sets the callback used to indicate that a new call exists.
     * \param newCallCb The callback.
     */
    void SetNewCallCb(const Callback<void, uint16_t> newCallCb) override;
    /**
     * Sets the server call pointer.
     * \param call The pointer back to the server call object.
     */
    void SetServerCall(Ptr<McpttServerCall> call) override;
    /**
     * Sets the userId to use for the server.
     * Normally, a SIP URI (string) but the model presently
     * uses integers in place of URIs
     * \param userId The user ID.
     */
    void SetUserId(uint32_t userId) override;
    /**
     * Starts the state machine.
     */
    void Start() override;
    /**
     * Stops the state machine.
     */
    void Stop() override;
    /**
     * Upgrades the call type.
     * \param callType The call type value.
     */
    void UpgradeCallType(uint8_t callType) override;

  protected:
    /**
     * Disposes of this McpttServerCallMachineNull instance.
     */
    void DoDispose() override;

  private:
    Ptr<McpttServerCall> m_serverCall; //!< The server call.
    uint16_t m_floorPort;              //!< The port number to use for floor control.
    uint16_t m_mediaPort;              //!< The port number to use for media.
    uint8_t m_callType;                //!< The call type.
    uint32_t m_userId;                 //!< The user ID.
};

} // namespace psc
} // namespace ns3

#endif /* MCPTT_SERVER_CALL_MACHINE_H */
