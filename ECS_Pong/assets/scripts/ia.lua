function updateIA(ballPosY, paddlePosY, paddleSpeedY)

    if ballPosY > paddlePosY then
        paddleSpeedY.value = 200 

    elseif ballPosY < paddlePosY then
        paddleSpeedY.value = -200 

    else
        paddleSpeedY.value = 0 
    end
end