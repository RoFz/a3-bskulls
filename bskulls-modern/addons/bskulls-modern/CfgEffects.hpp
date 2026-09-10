// Self-contained Archangel terminal-stage smoke. Keeping every inherited
// Missile4 value explicit prevents global particle replacements from changing
// the selected production appearance.
class CfgCloudlets
{
    class Default;

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
