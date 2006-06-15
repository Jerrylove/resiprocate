#if !defined(RESIP_REGISTRATIONPERSISTENCEMANAGER_HXX)
#define RESIP_REGISTRATIONPERSISTENCEMANAGER_HXX

#include <list>
#include "resiprocate/Uri.hxx"
#include "resiprocate/dum/Win32ExportDum.hxx"

namespace resip
{

class DUM_API RegistrationPersistenceManager
{
  public:
    typedef std::pair<Uri,time_t> ContactPair;
    typedef std::list<ContactPair> ContactPairList;
    typedef std::list<Uri> UriList;

    typedef enum
    {
      CONTACT_CREATED,
      CONTACT_UPDATED
    } update_status_t;

    RegistrationPersistenceManager() {}
    virtual ~RegistrationPersistenceManager() {}

    virtual void addAor(Uri &aor, ContactPairList contacts = ContactPairList()) = 0;
    virtual void removeAor(Uri &aor) = 0;
    virtual bool aorIsRegistered(Uri &aor) = 0;
 
    virtual void lockRecord(Uri &aor) = 0;
    virtual void unlockRecord(Uri &aor) = 0;

     virtual UriList getAors() = 0;

    /**
      @param expires Absolute time of expiration, measured in seconds
                     since midnight January 1st, 1970.
     */
    virtual update_status_t updateContact(Uri &aor, Uri &contact, time_t expires) = 0;

    virtual void removeContact(Uri &aor, Uri &contact) = 0;

    virtual ContactPairList getContacts(Uri &aor) = 0;
  private:
};

}

#endif

/* ====================================================================
 * The Vovida Software License, Version 1.0 
 * 
 * Copyright (c) 2000 Vovida Networks, Inc.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The names "VOCAL", "Vovida Open Communication Application Library",
 *    and "Vovida Open Communication Application Library (VOCAL)" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact vocal@vovida.org.
 *
 * 4. Products derived from this software may not be called "VOCAL", nor
 *    may "VOCAL" appear in their name, without prior written
 *    permission of Vovida Networks, Inc.
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL VOVIDA
 * NETWORKS, INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 * IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by Vovida
 * Networks, Inc. and many individuals on behalf of Vovida Networks,
 * Inc.  For more information on Vovida Networks, Inc., please see
 * <http://www.vovida.org/>.
 *
 */
