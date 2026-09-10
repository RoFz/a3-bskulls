// Self-contained Archangel launch and terminal-stage smoke. Keeping every
// value explicit prevents global particle replacements from changing the
// selected production appearance.
class CfgCloudlets
{
    class Default;

    // Brief, compact trail while the launch motor ejects the carrier. This is
    // driven by effectsMissileInit and therefore stops when initTime expires
    // and the inherited Titan flight-motor effect begins.
    class B_PTbskull_ArchangelSoftLaunchSmoke : Default
    {
        interval = 0.004;
        circleRadius = 0;
        circleVelocity[] = {0,0,0};
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        particleFSLoop = 0;
        angle = 0;
        angleVar = 1;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 0.9;
        moveVelocity[] = {0,0,0};
        rotationVelocity = 1;
        weight = 1.05;
        volume = 1;
        rubbing = 0.35;
        size[] = {0.16,0.38,0.7};
        sizeCoef = 1;
        color[] = {
            {0.82,0.82,0.82,0.5},
            {0.9,0.9,0.9,0.22},
            {0.96,0.96,0.96,0}
        };
        colorCoef[] = {1,1,1,1};
        animationSpeed[] = {1};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.08;
        randomDirectionIntensity = 0.08;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 0.12;
        position[] = {0,0,0};
        positionVar[] = {0.025,0.025,0.025};
        positionVarConst[] = {0,0,0};
        moveVelocityVar[] = {0.22,0.22,0.22};
        moveVelocityVarConst[] = {0,0,0};
        rotationVelocityVar = 14;
        sizeVar = 0.08;
        colorVar[] = {0,0,0,0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };

    class B_PTbskull_ArchangelMissile4Visible : Default
    {
        interval = 0.002;
        circleRadius = 0;
        circleVelocity[] = {0,0,0};
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        particleFSLoop = 0;
        angle = 0;
        angleVar = 1;
        animationName = "";
        particleType = "Billboard";
        timerPeriod = 1;
        lifeTime = 3.2;
        moveVelocity[] = {0,0,0};
        rotationVelocity = 1;
        weight = 1;
        volume = 0.8;
        rubbing = 0.5;
        size[] = {1.2,2.6,4.2};
        sizeCoef = 1;
        color[] = {
            {0.86,0.86,0.86,0.4},
            {0.94,0.94,0.94,0.16},
            {1,1,1,0}
        };
        colorCoef[] = {1,1,1,1};
        animationSpeed[] = {1};
        animationSpeedCoef = 1;
        randomDirectionPeriod = 0.1;
        randomDirectionIntensity = 0.1;
        onTimerScript = "";
        beforeDestroyScript = "";
        blockAIVisibility = 0;
        lifeTimeVar = 0.25;
        position[] = {0,0,0};
        positionVar[] = {0.1,0.1,0.1};
        positionVarConst[] = {0,0,0};
        moveVelocityVar[] = {0.24,0.24,0.24};
        moveVelocityVarConst[] = {0,0,0};
        rotationVelocityVar = 20;
        sizeVar = 0.2;
        colorVar[] = {0,0,0,0};
        randomDirectionPeriodVar = 0;
        randomDirectionIntensityVar = 0;
    };
};

// BI documents effectsMissileInit as the pre-engine real-time missile effect;
// its density input falls from 1 to 0 across initTime:
// https://community.bistudio.com/wiki/Arma_3:_Particle_Effects:_Config_Parameters
class B_PTbskull_ArchangelSoftLaunchEffect
{
    class EjectionSmoke
    {
        simulation = "particles";
        type = "B_PTbskull_ArchangelSoftLaunchSmoke";
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        qualityLevel = -1;
        // density falls from 1 to 0 over initTime. Keep emitting through the
        // ejection coast, then stop immediately before flight-motor ignition.
        enabled = "(density interpolate [0.01,0.02,-1,1])";
    };
};
