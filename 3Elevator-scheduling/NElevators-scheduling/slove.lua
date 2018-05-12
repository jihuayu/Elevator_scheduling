function scheduler(...) {
    local mincost = 10000000;
	req={...}
	local now=req[1]
	for i=2, #(req) do  
		local costup=0
		local costdown=0
		if req[i]>now then
			costup=costup+1
			costdown=costdown-2
		end
		if req[i]<now then
			costup=costup-2
			costdown=costdown+1
		end
	end
	if costup>costdown 
	then
		return 1
	else 
		return -1
end