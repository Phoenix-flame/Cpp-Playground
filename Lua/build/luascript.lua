print("Phoenix_flame")

width = 20
height = 20

function check_bounderies_x()
    if ((pos_x > width) or (pos_x < 0))
    then
        return true
    end 
    return false 
end
function check_bounderies_y()
    if ((pos_y > height) or (pos_y < 0))
    then
        return true
    end
    return false
end

function update(dt)
    if (check_bounderies_x())
    then
        -- print("x collision")
        speed_x = speed_x * -1
    end
    if (check_bounderies_y())
    then
        -- print("y collision")
        speed_y = speed_y * -1
    end
    pos_x = pos_x + dt * speed_x;
    pos_y = pos_y + dt * speed_y;
    
    return pos_x, pos_y
end

function myluafunction(times)
    return string.rep("(-)", times) 
end

function myfunction(arg)
  return cppfunction(arg)
end
