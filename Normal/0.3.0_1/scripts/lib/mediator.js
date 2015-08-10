(function(e,t){define([],function(){return t()()})})(this,function(){function e(){var e=function(){return((1+Math.random())*65536|0).toString(16).substring(1)};return e()+e()+"-"+e()+"-"+e()+"-"+e()+"-"+e()+e()+e()}function t(n,r,i){if(!(this instanceof t))return new t(n,r,i);this.id=e(),this.fn=n,this.options=r,this.context=i,this.channel=null}function n(e,t){if(!(this instanceof n))return new n(e);this.namespace=e||"",this._subscribers=[],this._channels={},this._parent=t,this.stopped=!1}function r(){if(!(this instanceof r))return new r;this._channels=new n("")}return t.prototype={update:function(e){e&&(this.fn=e.fn||this.fn,this.context=e.context||this.context,this.options=e.options||this.options,this.channel&&this.options&&this.options.priority!==undefined&&this.channel.setPriority(this.id,this.options.priority))}},n.prototype={addSubscriber:function(e,n,r){var i=new t(e,n,r);return n&&n.priority!==undefined?(n.priority=n.priority>>0,n.priority<0&&(n.priority=0),n.priority>=this._subscribers.length&&(n.priority=this._subscribers.length-1),this._subscribers.splice(n.priority,0,i)):this._subscribers.push(i),i.channel=this,i},stopPropagation:function(){this.stopped=!0},getSubscriber:function(e){var t=0,n=this._subscribers.length;for(t,n;t<n;t++)if(this._subscribers[t].id===e||this._subscribers[t].fn===e)return this._subscribers[t]},setPriority:function(e,t){var n=0,r=0,i,s,o,u;for(r=0,u=this._subscribers.length;r<u;r++){if(this._subscribers[r].id===e||this._subscribers[r].fn===e)break;n++}i=this._subscribers[n],s=this._subscribers.slice(0,n),o=this._subscribers.slice(n+1),this._subscribers=s.concat(o),this._subscribers.splice(t,0,i)},addChannel:function(e){this._channels[e]=new n((this.namespace?this.namespace+":":"")+e,this)},hasChannel:function(e){return this._channels.hasOwnProperty(e)},returnChannel:function(e){return this._channels[e]},removeSubscriber:function(e){var t=this._subscribers.length-1;if(!e){this._subscribers=[];return}for(t;t>=0;t--)if(this._subscribers[t].fn===e||this._subscribers[t].id===e)this._subscribers[t].channel=null,this._subscribers.splice(t,1)},publish:function(e){var t=0,n=this._subscribers.length,r=!1,i,s,o,u;for(t,n;t<n;t++)r=!1,i=this._subscribers[t],this.stopped||(o=this._subscribers.length,i.options!==undefined&&typeof i.options.predicate=="function"?i.options.predicate.apply(i.context,e)&&(r=!0):r=!0),r&&(i.options&&i.options.calls!==undefined&&(i.options.calls--,i.options.calls<1&&this.removeSubscriber(i.id)),i.fn.apply(i.context,e),u=this._subscribers.length,n=u,u===o-1&&t--);this._parent&&this._parent.publish(e),this.stopped=!1}},r.prototype={getChannel:function(e,t){var n=this._channels,r=e.split(":"),i=0,s=r.length;if(e==="")return n;if(r.length>0)for(i,s;i<s;i++){if(!n.hasChannel(r[i])){if(t)break;n.addChannel(r[i])}n=n.returnChannel(r[i])}return n},subscribe:function(e,t,n,r){var i=this.getChannel(e||"",!1);return n=n||{},r=r||{},i.addSubscriber(t,n,r)},once:function(e,t,n,r){return n=n||{},n.calls=1,this.subscribe(e,t,n,r)},getSubscriber:function(e,t){var n=this.getChannel(t||"",!0);return n.namespace!==t?null:n.getSubscriber(e)},remove:function(e,t){var n=this.getChannel(e||"",!0);if(n.namespace!==e)return!1;n.removeSubscriber(t)},publish:function(e){var t=this.getChannel(e||"",!0);if(t.namespace!==e)return null;var n=Array.prototype.slice.call(arguments,1);n.push(t),t.publish(n)}},r.prototype.on=r.prototype.subscribe,r.prototype.bind=r.prototype.subscribe,r.prototype.emit=r.prototype.publish,r.prototype.trigger=r.prototype.publish,r.prototype.off=r.prototype.remove,r.Channel=n,r.Subscriber=t,r.version="0.9.8",r});