/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Assertion_hpp
#define Assertion_hpp

#include <WCDB/Console.hpp>

// Inner assert is for WCDB debugging only, which will be removed when released.
// Remedial assertion will abort or result in error when it's Console::debuggable accoding to the configuration

#ifdef DEBUG

#define WCTInnerAssert(cond)                                                                 \
    if (!(cond)) {                                                                           \
        WCDB::Console::fatal(                                                                \
        "If you think it's a bug caused by WCDB, please report to us.", __FILE__, __LINE__); \
    }

#else // DEBUG

#define WCTInnerAssert(cond)

#endif // DEBUG

#warning TODO check all assertion to confirm their correctness
#define WCTRemedialAssert(cond, message, remedial)                             \
    if (!(cond)) {                                                             \
        WCDB::Console::fatal((message), __FILE__, __LINE__);                   \
        remedial                                                               \
    }

#endif /* Assertion_hpp */
