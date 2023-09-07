/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/07/17.
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_POLICY_H
#define VIRTRU_TDF3_SDK_VIRTRU_POLICY_H

#include <string>
#include <vector>
#include <unordered_set>
#include <memory>

namespace virtru {

    /// Forward declaration
    class Client;
    class VirtruPolicyObject;

    class Policy {
    public:
        /// Constructor
        Policy();

        /// Destructor
        ~Policy();

        /// Copy constructor
        Policy(const Policy& policy);

        /// Assignment operator
        Policy& operator=(const Policy& policy);

        /// Move copy constructor
        Policy(Policy&& policy) noexcept ;

        /// Move assignment operator
        Policy& operator=(Policy&& policy);

    public: // Virtru controls
        /// Set the owner of the TDF
        /// \param owner - The owner's email address
        /// NOTE: By default, the owner is the address that was used when the client instance was created.
        /// This method will change the owner to the specified email address for the instance.
        void setOwner(const std::string& owner);

        /// Return the owner of the TDF.
        /// \return owner - The owner's email address.
        /// NOTE: If the owner is not set, an empty string is return.
        std::string getOwner() const;

        /// Add access to the TDF file/data for the users in the list
        /// \param users - Share the TDF with the users in the vector
        void shareWithUsers(const std::vector<std::string>& users);

        /// Remove access to the TDF file/data for the users in the list
        /// \param users - Remove access to the TDF file/data for the users in the vector
        void removeUsers(const std::vector<std::string>& users);

        /// Return all the user who have access to the TDF.
        /// \return users - All the user who have access to the TDF.
        std::vector<std::string> getSharedUsers() const;

        /// Turns on reshare policy control flag
        void enableReshare();

        /// Turns off reshare policy control flag
        void disableReshare();

        /// Return the status of 'Reshare' control flag.
        /// \return bool - True, if 'Reshare' control flag is set.
        bool isReshareEnabled() const;

        /// Turns on watermarking policy control flag
        void enableWatermarking();

        /// Turns off watermarking policy control flag
        void disableWatermarking();

        /// Return the status of 'Watermarking' control flag.
        /// \return bool - True, if 'Watermarking' control flag is set.
        bool isWatermarkingEnabled() const;

        /// Turns on print policy control flag
        void enablePrint();

        /// Turns off print policy control flag
        void disablePrint();

        /// Return the status of 'Print' control flag.
        /// \return bool - True, if 'Print' control flag is set.
        bool isPrintEnabled() const;

        /// Turns on copy policy control flag
        void enableCopy();

        /// Turns off copy policy control flag
        void disableCopy();

        /// Return the status of 'Copy' control flag.
        /// \return bool - True, if 'Copy' control flag is set.
        bool isCopyEnabled() const;

        /// Turns on persistent protection policy control flag
        void enablePersistentProtection();

        /// Turns off persistent protection policy control flag
        void disablePersistentProtection();

        /// Return the status of 'PersistenProtection' control flag.
        /// \return bool - True, if 'PersistentProtection' control flag is set.
        bool isPersistentProtectionEnabled() const;

        /// Turns on prevent download policy control flag
        void enablePreventDownload();

        /// Turns off prevent download policy control flag
        void disablePreventDownload();

        /// Return the status of 'PreventDownload' control flag.
        /// \return bool - True, if 'PreventDownload' control flag is set.
        bool isPreventDownloadEnabled() const;

        /// Set the expiration in minutes\n
        /// Access to the TDF data will be revoked for all users in the number of minutes specified, starting from the time this call is made.  The owner will retain access after the expiration time is reached.
        /// \param mins - minutes until expiration
        void expireInMins(unsigned mins);

        /// Set the expiration in days\n
        /// Access to the TDF data will be revoked for all users in the number of days specified, starting from the time this call is made.  The owner will retain access after the expiration time is reached.
        /// \param days - days until expiration
        void expireInDays(unsigned days);

        /// Access to the TDF data will be revoked for all users at the specified date.  The owner will retain access after the expiration time is reached.
        /// The expiration date is specified in ISO-8601 format, and can include a time component.  Ex: 2019-05-24T16:12:41Z
        /// \param expirationDate - Expiration date when the TDF will expire
        void addExpiration(const std::string& expirationDate);

        /// Remove the expiration
        void removeExpiration();

        /// Return the expiration time(in ISO-8601 format) of the TDF.
        /// \return string - The expiration time(in ISO-8601 format) of the TDF.
        /// NOTE: If the expiration is not set, an empty string is return.
        std::string getExpiration() const;

        /// Return the description of all the policy controls of the instance.
        /// \return - A formated string of all the policy controls of the instance.
        std::string toString() const;

    private:
        /// Expresses the policy as a json string for KAS
        /// \return - Json fomated string.
        std::string toJsonStringForKas() const;

        /// Apply the policy control on to policyObject.
        /// \param policyObject - The VirtruPolicyObject.
        void applyPolicy(VirtruPolicyObject& policyObject) const;

    private: // Not supported yet
        /// Turns on one-click flag
        void enableOneClick();

        /// Turns off one-click flag
        void disableOneClick();

    private:
        friend Client;
        friend VirtruPolicyObject;

        struct Impl;
        std::unique_ptr<Impl> m_impl;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_POLICY_H
