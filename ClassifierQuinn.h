#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class Classifier {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[2] = { 0 };
                        // tree #1
                        if (x[4] <= -7.475199937820435) {
                            if (x[11] <= 8.454999923706055) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[17] <= 2.4700000286102295) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[21] <= 0.8855502009391785) {
                                if (x[5] <= 2.6636310815811157) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[4] <= -0.6434000134468079) {
                                    if (x[0] <= -5.924999952316284) {
                                        if (x[1] <= -1.2350000143051147) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[14] <= 10.5) {
                                                if (x[3] <= 12.240000247955322) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #2
                        if (x[3] <= 10.809999942779541) {
                            if (x[20] <= 8.736000061035156) {
                                if (x[19] <= 12.180000305175781) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[15] <= 14.5) {
                                    if (x[21] <= 0.2751636281609535) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[4] <= 3.549399733543396) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #3
                        if (x[1] <= -0.17999999970197678) {
                            if (x[3] <= 11.045000076293945) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[17] <= 1.4500000551342964) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[10] <= 7.174999952316284) {
                                if (x[5] <= 2.185532510280609) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[7] <= 18.0) {
                                        if (x[11] <= 10.650000095367432) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[21] <= 2.792188823223114) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #4
                        if (x[17] <= 10.019999980926514) {
                            if (x[19] <= 8.610000133514404) {
                                if (x[16] <= -8.394999980926514) {
                                    if (x[20] <= -7.1468000411987305) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 0.3699999898672104) {
                                        if (x[12] <= -1.18340003490448) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[4] <= -2.7423999905586243) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[5] <= 3.3573694229125977) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[5] <= 2.4081867337226868) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[14] <= 19.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[8] <= 0.8399999812245369) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #5
                        if (x[3] <= 10.809999942779541) {
                            if (x[20] <= 8.705199718475342) {
                                if (x[2] <= 0.1600000001490116) {
                                    if (x[16] <= -9.84499979019165) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[13] <= 0.39457273483276367) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 9.260000228881836) {
                                if (x[6] <= 7.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #6
                        if (x[19] <= 8.490000247955322) {
                            if (x[9] <= 7.884999990463257) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[10] <= 7.295000076293945) {
                                    if (x[21] <= 0.7179857194423676) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[19] <= 2.8799999952316284) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[3] <= 5.075000047683716) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[4] <= 1.9515999555587769) {
                                    if (x[7] <= 18.0) {
                                        if (x[10] <= 1.899999976158142) {
                                            if (x[10] <= 0.8799999952316284) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[12] <= -2.509600043296814) {
                                                    if (x[2] <= 1.0199999809265137) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #7
                        if (x[4] <= -7.519599914550781) {
                            if (x[17] <= 8.375) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[3] <= 11.28000020980835) {
                                if (x[19] <= 10.019999980926514) {
                                    if (x[0] <= -9.945000171661377) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[13] <= 0.7465871572494507) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[20] <= 8.329800128936768) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #8
                        if (x[2] <= 0.6099999845027924) {
                            if (x[3] <= 5.900000095367432) {
                                if (x[0] <= -5.5899999141693115) {
                                    if (x[1] <= 2.019999921321869) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[4] <= 1.513600006699562) {
                                    if (x[7] <= 17.5) {
                                        if (x[11] <= 10.650000095367432) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[9] <= 2.625) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[5] <= 2.870002269744873) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #9
                        if (x[17] <= 10.019999980926514) {
                            if (x[19] <= 8.490000247955322) {
                                if (x[5] <= 3.738274931907654) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[3] <= 9.46999979019165) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[5] <= 2.4081867337226868) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[5] <= 2.1466063857078552) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #10
                        if (x[0] <= -10.809999942779541) {
                            if (x[22] <= 18.0) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[17] <= 10.019999980926514) {
                                if (x[16] <= -12.380000114440918) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[4] <= -0.8325999975204468) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[18] <= 8.355000019073486) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[23] <= 12.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[12] <= 0.7486000657081604) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 2; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Active Brushing";
                            case 1:
                            return "Not Brushing";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }