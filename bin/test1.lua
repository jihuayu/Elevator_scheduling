function scheduler (...)

	req={...}
	if (#(req)==1)
	then 
		return 0
	else
		now=req[1]
		costup=0
		costdown=0
		for i=1, #(req) do  
			if (req[i]>now) then
				costup=costup+1
				costdown=costdown-2
			end
			if (req[i]<now) then
				costup=costup-2
				costdown=costdown+1
			end
		end
		if (costup>costdown)
		then
			return -1
		else 
			return 1
		end
	end
end